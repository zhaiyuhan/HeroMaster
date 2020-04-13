from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtGui import *
class ControlPlaneView(QWidget):
    def __init__(self, parent=None):
        super(ControlPlaneView, self).__init__(parent)
        self.Stack = QStackedWidget(self)
        self.TextView = QWidget()
        self.createPlaneForTextView()
        self.Stack.addWidget(self.TextView)

    def createPlaneForTextView(self):
        m_mainlayout = QHBoxLayout()
        m_newfileToolButton = QToolButton();
        m_savefileToolButton = QToolButton();
        m_savefileToolButton.setText("Save File")
        m_savefileToolButton.setIcon(QIcon(":/TextView/icon_file_open.png"))
        m_savefileToolButton.setToolButtonStyle(Qt.ToolButtonTextUnderIcon)
        m_mainlayout.addWidget(m_savefileToolButton)
        m_copyToolButton = QToolButton();
        m_copyToolButton.setText("Copy")
        m_copyToolButton.setIcon(QIcon(":/TextView/icon_new_file.png"))
        m_copyToolButton.setToolButtonStyle(Qt.ToolButtonTextUnderIcon)
        m_mainlayout.addWidget(m_copyToolButton)
        m_pasteToolButton = QToolButton();
        m_pasteToolButton.setText("Paste")
        m_pasteToolButton.setIcon(QIcon(":/TextView/icon_paste.png"))
        m_pasteToolButton.setToolButtonStyle(Qt.ToolButtonTextUnderIcon)
        m_mainlayout.addWidget(m_pasteToolButton)
        m_deleteButton = QToolButton();
        m_deleteButton.setText("Delete")
        m_deleteButton.setIcon(QIcon(":/TextView/icon_new_file.png"))
        m_deleteButton.setToolButtonStyle(Qt.ToolButtonTextUnderIcon)
        m_mainlayout.addWidget(m_deleteButton)
        m_printButton = QToolButton();
        m_printButton.setText("Print")
        m_printButton.setIcon(QIcon(":/TextView/icon_print.png"))
        m_printButton.setToolButtonStyle(Qt.ToolButtonTextUnderIcon)
        m_mainlayout.addWidget(m_printButton)
        m_undoButton = QToolButton();
        m_undoButton.setText("Undo")
        m_undoButton.setIcon(QIcon(":/TextView/icon_new_file.png"))
        m_undoButton.setToolButtonStyle(Qt.ToolButtonTextUnderIcon)
        m_mainlayout.addWidget(m_undoButton)

        self.TextView.setLayout(m_mainlayout)
