from PyQt5.QtWidgets import *

class PlaneForTextView(QWidget):
    def __init__(self, parent=None):
        super(PlaneForTextView, self).__init__(parent)
        m_mainStackedWidget = QStackedWidget()