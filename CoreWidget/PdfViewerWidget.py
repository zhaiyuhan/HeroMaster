import os
import time
import multiprocessing as mp
import queue
import fitz
from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtGui import *
class PdfViewer(QWidget):
    def __init__(self, parent=None):
        super(PdfViewer, self).__init__(parent)
        self.process = None
        self.queNum = mp.Queue()
        self.queDoc = mp.Queue()
        self.pageCount = 0
        self.curPageNum = 0
        self.lastDir = ''
        self.timerSend = QTimer(self)
        self.timerSend.timeout.connect(self.onTimerSendPageNum)
        self.timerGet = QTimer(self)
        self.timerGet.timeout.connect(self.onTimerGetPage)
        self.timerWaiting = QTimer(self)
        self.timerWaiting.timeout.connect(self.onTimerWaiting)
        self.initUI()

    def initUI(self):
        vbox = QVBoxLayout()
        self.setLayout(vbox)

        hbox = QHBoxLayout()
        self.btnOpen = QPushButton('OpenDocument', self)
        self.btnOpen.clicked.connect(self.openDoc)
        hbox.addWidget(self.btnOpen)

        self.btnPlay = QPushButton('PlayDocument', self)
        self.btnPlay.clicked.connect(self.playDoc)
        hbox.addWidget(self.btnPlay)

        self.btnStop = QPushButton('Stop', self)
        self.btnStop.clicked.connect(self.stopPlay)
        hbox.addWidget(self.btnStop)

        self.label = QLabel('0/0', self)
        self.label.setFont(QFont('Verdana', 20))
        hbox.addWidget(self.label)

        vbox.addLayout(hbox)

        self.labelImg = QLabel('Document', self)
        sizePolicy = QSizePolicy(QSizePolicy.Preferred, QSizePolicy.Expanding)
        self.labelImg.setSizePolicy(sizePolicy)
        vbox.addWidget(self.labelImg)

        self.setWindowTitle('PyMuPDF Document Player')

    def openDoc(self):
        path, _ = QFileDialog.getOpenFileName(self, "Open Document", self.lastDir,
                                                        "All Supported Files (*.pdf;*.epub;*.xps;*.oxps;*.cbz;*.fb2);;PDF Files (*.pdf);;EPUB Files (*.epub);;XPS Files (*.xps);;OpenXPS Files (*.oxps);;CBZ Files (*.cbz);;FB2 Files (*.fb2)",
                                                        options=QFileDialog.Options())
        if path:
            self.lastDir, self.file = os.path.split(path)
            if self.process:
                self.queNum.put(-1)  # use -1 to notify the process to exit
            self.timerSend.stop()
            self.curPageNum = 0
            self.pageCount = 0
            self.process = mp.Process(target=self.openDocInProcess, args=(path, self.queNum, self.queDoc))
            self.process.start()
            self.timerGet.start(40)
            self.label.setText('0/0')
            self.queNum.put(0)
            self.startTime = time.perf_counter()
            self.timerWaiting.start(40)

    def playDoc(self):
        self.timerSend.start(500)

    def stopPlay(self):
        self.timerSend.stop()

    def onTimerSendPageNum(self):
        if self.curPageNum < self.pageCount - 1:
            self.queNum.put(self.curPageNum + 1)
        else:
            self.timerSend.stop()

    def onTimerGetPage(self):
        try:
            ret = self.queDoc.get(False)
            if isinstance(ret, int):
                self.timerWaiting.stop()
                self.pageCount = ret
                self.label.setText('{}/{}'.format(self.curPageNum + 1, self.pageCount))
            else:  # tuple, pixmap info
                num, samples, width, height, stride, alpha = ret
                self.curPageNum = num
                self.label.setText('{}/{}'.format(self.curPageNum + 1, self.pageCount))
                fmt = QImage.Format_RGBA8888 if alpha else QImage.Format_RGB888
                qimg = QImage(samples, width, height, stride, fmt)
                self.labelImg.setPixmap(QPixmap.fromImage(qimg))
        except queue.Empty as ex:
            pass

    def onTimerWaiting(self):
        self.labelImg.setText('Loading "{}", {:.2f}s'.format(self.file, time.perf_counter() - self.startTime))

    def closeEvent(self, event):
        self.queNum.put(-1)
        event.accept()

    def openDocInProcess(path, queNum, quePageInfo):
        doc = fitz.open(path)
        quePageInfo.put(doc.pageCount)
        while True:
            num = queNum.get()
            if num < 0:
                break
            page = doc.loadPage(num)
            pix = page.getPixmap()
            quePageInfo.put((num, pix.samples, pix.width, pix.height, pix.stride, pix.alpha))
        doc.close()
        print('process exit')