#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initUI();
}

MainWindow::~MainWindow()
{

}

void MainWindow::setupUI()
{
    createMenus();
    statusBar();
    statusBar()->setSizeGripEnabled(false);
    statusBar()->setStyleSheet(QString("QStatusBar::item{border:0px}"));
    m_ConsoleButton = new QPushButton("No Result",this);
    m_ConsoleButton->resize(QSize(40,20));
    m_ConsoleButton->setToolTip(QString("Click to know more"));
    statusBar()->addWidget(m_ConsoleButton);
    m_tooltipLabel = new QLabel(this);
    statusBar()->addWidget(m_tooltipLabel);
}

void MainWindow::initUI()
{
    setWindowTitle("HeroMaster 2000");
    setMinimumSize(QSize(800,600));
    QDesktopWidget *desktop = QApplication::desktop();
    move((desktop->width()-this->width())/2,(desktop->height()-this->height())/2);
    setupUI();

}

void MainWindow::createActions()
{
    //m_mainfileGroup = new QActionGroup(this);
    m_newfileAction = new QAction("New File");
    m_openfileAction = new QAction("Open File");
    m_exitAction = new QAction("Exit");
    m_toggleFullScreenAction = new QAction("Full Screen");
}

void MainWindow::createMenus()
{
    createActions();
    m_mainMenuBar = new QMenuBar(this);
    setMenuBar(m_mainMenuBar);
    m_fileMenu = new QMenu("File");
    m_mainMenuBar->addMenu(m_fileMenu);
    m_fileMenu->addAction(m_newfileAction);
    m_newfileAction->setStatusTip(QString("Create a new file"));
    //connect(m_newfileAction, &QAction::hovered, [=](){ m_tooltipLabel->setText(QString("Create a new file")); });
    m_fileMenu->addAction(m_openfileAction);
    m_openfileAction->setStatusTip(QString("Open a file"));
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_exitAction);
    m_exitAction->setStatusTip(QString("Exit the application"));
    connect(m_exitAction, &QAction::triggered, [=](){ qApp->exit();});
    m_editMenu = new QMenu("Edit");
    m_mainMenuBar->addMenu(m_editMenu);
    m_viewMenu = new QMenu("View");
    m_mainMenuBar->addMenu(m_viewMenu);
    m_viewMenu->addAction(m_toggleFullScreenAction);
    m_toggleFullScreenAction->setCheckable(true);
    m_toggleFullScreenAction->setChecked(false);
    connect(m_toggleFullScreenAction, &QAction::toggled, [=]() {
        if(m_toggleFullScreenAction->isChecked() == true) showFullScreen();
        if(m_toggleFullScreenAction->isChecked() == false) showNormal();
    });
    m_helpMenu = new QMenu("Help");
    m_mainMenuBar->addMenu(m_helpMenu);
}
