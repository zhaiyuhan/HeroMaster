from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from CoreWidget.TextEditor import *
from CoreWidget.PdfViewerWidget import *
class MainView(QWidget):
    def __init__(self, parent=None):
        super(MainView, self).__init__(parent)
        m_mainlayout = QVBoxLayout()
        self.setLayout(m_mainlayout)
        m_textviewButton = QPushButton("Text View")
        m_textviewButton.setFixedSize(150, 30);
        m_audioviewButton = QPushButton("Audio View")
        m_audioviewButton.setFixedSize(150, 30);
        m_videoviewButton = QPushButton("Video View")
        m_videoviewButton.setFixedSize(150, 30);
        m_cameraviewButton = QPushButton("Camera View")
        m_cameraviewButton.setFixedSize(150, 30);
        m_buttonlayout = QHBoxLayout()
        m_buttonlayout.setSpacing(5)
        m_buttonlayout.setAlignment(m_mainlayout, Qt.AlignCenter)
        m_mainlayout.addLayout(m_buttonlayout)
        m_buttonlayout.addWidget(m_textviewButton)
        m_buttonlayout.addWidget(m_audioviewButton)
        m_buttonlayout.addWidget(m_videoviewButton)
        m_buttonlayout.addWidget(m_cameraviewButton)

        m_mainMDIArea = QMdiArea()
        m_mainMDIArea.setBackground(QBrush(QColor("#333333")))
        m_mainlayout.addWidget(m_mainMDIArea)

        testwidget = TextEditor()
        testwidget.setWindowIcon(QIcon(""))
        m_mainMDIArea.addSubWindow(testwidget)

        pdfWidget = PdfViewer(self)
        m_mainMDIArea.addSubWindow(pdfWidget)

