from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtGui import *
class FileBrowser(QWidget):
    def __init__(self, parent=None):
        super(FileBrowser, self).__init__(parent)
        self.Stack = QStackedWidget(self)

        m_addfileButton = QPushButton("Add File")
        m_addfileButton.setFixedHeight(25)