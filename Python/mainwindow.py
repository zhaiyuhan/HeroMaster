from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
import Resources.Resources_rc
from enum import Enum

class LastWindowState(Enum):
    L_NORMAL = 1
    L_MIINIMIZED = 2
    L_MAXIMIZED = 3
    L_FULLSCREEN = 4

class MainWindow(QMainWindow):

    def __init__(self, parent=None):
        super(MainWindow, self).__init__(parent)
        self.initUI()
        self.m_ConsoleButton = QPushButton("No Result")
        self.m_ConsoleButton.setStyleSheet("QStatusBar::item{border:0px}")
        self.m_ConsoleButton.resize(QSize(40,20))
        self.statusBar = QStatusBar()
        self.setStatusBar(self.statusBar)
        self.statusBar.addPermanentWidget(self.m_ConsoleButton)
        self.createMenus()
        self.createToolBar()

    def initUI(self):
        self.setWindowTitle("Hero Master 2000")
        self.setMinimumSize(QSize(1024, 768))
        self.setWindowIcon(QIcon(":/AppIcon/king.png"))
        desktop = QApplication.desktop();
        self.move((desktop.width() - self.width()) / 2, (desktop.height() - self.height()) / 2);

    def createMenus(self):
        m_mainMenuBar = self.menuBar()
        m_fileMenu = m_mainMenuBar.addMenu("File")
        m_newfileAction = QAction("New File", self)
        m_openfileAction = QAction("Open File", self)
        m_exitAction = QAction("Exit", self)
        m_fileMenu.addAction(m_newfileAction)
        m_fileMenu.addAction(m_openfileAction)
        m_fileMenu.addSeparator()
        m_fileMenu.addAction(m_exitAction)

        m_editMenu = m_mainMenuBar.addMenu("Edit")

        m_viewMenu = m_mainMenuBar.addMenu("View")
        m_maximizedAction = QAction("Maximized", self)
        m_minminizedAction = QAction("Minimized", self)
        m_normalAction = QAction("Normal", self)
        m_toggleFullScreenAction = QAction("Full Screen", self)
        m_viewMenu.addAction(m_maximizedAction)
        m_viewMenu.addAction(m_minminizedAction)
        m_viewMenu.addAction(m_normalAction)
        m_viewMenu.addAction(m_toggleFullScreenAction)

        m_helpMenu = m_mainMenuBar.addMenu("Help")
        m_openhelpAction = QAction("Help", self)
        m_openAboutViewAction = QAction("About", self)
        m_helpMenu.addAction(m_openhelpAction)
        m_helpMenu.addSeparator()
        m_helpMenu.addAction(m_openAboutViewAction)

    def createToolBar(self):
        m_mainToolBar = self.addToolBar("")
        m_mainToolBar.setToolButtonStyle(Qt.ToolButtonTextBesideIcon)
        m_TnewfileAction = QAction("Create New File", self)
        m_TnewfileAction.setIcon(QIcon(":/ToolButton/ToolBar_NewFile.png"))
        m_mainToolBar.addAction(m_TnewfileAction)

        m_TopenfileAction = QAction("Open File", self)
        m_TopenfileAction.setIcon(QIcon(":/ToolButton/ToolBar_OpenFile.png"))
        m_mainToolBar.addAction(m_TopenfileAction)
