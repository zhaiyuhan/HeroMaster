#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_mainview = new MainView(this);
    QFile maintheme(":/mainTheme.qss");
    if(maintheme.open(QFile::ReadOnly))
    {
        QString style = QLatin1String(maintheme.readAll());
        this->setStyleSheet(style);
        maintheme.close();
    }
    initUI();
    initEvents();
    setWindowFlags(Qt::FramelessWindowHint);
}

MainWindow::~MainWindow()
{

}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "/home",
                                                      tr("Music File (*.mp3)"));
    m_controlPlaneView->playmusic(fileName);
}

void MainWindow::setupUI()
{
    createMenus();
    createToolBar();
    createDockWindows();
    statusBar();
    statusBar()->setSizeGripEnabled(false);
    statusBar()->setStyleSheet(QString("QStatusBar::item{border:0px}"));
    m_ConsoleButton = new QPushButton("No Result",this);
    m_ConsoleButton->resize(QSize(40,20));
    m_ConsoleButton->setToolTip(QString("Click to know more"));
    statusBar()->addPermanentWidget(m_ConsoleButton);

    this->setCentralWidget(m_mainview);

}

void MainWindow::initUI()
{
    setWindowTitle("HeroMaster 2000");
    setMinimumSize(QSize(1024,768));
    setWindowIcon(QIcon(":/king.png"));
    QDesktopWidget *desktop = QApplication::desktop();
    move((desktop->width()-this->width())/2,(desktop->height()-this->height())/2);
    setupUI();
}

void MainWindow::initEvents()
{
    connect(m_openfileAction, &QAction::triggered, [=] { openFile(); });
}

void MainWindow::createActions()
{
    //filemenu
    m_newfileAction = new QAction("New File");
    m_newfileAction->setStatusTip(QString("Create a new file"));
    m_openfileAction = new QAction("Open File");
    m_openfileAction->setStatusTip(QString("Open a file"));
    m_exitAction = new QAction("Exit");
    m_exitAction->setStatusTip(QString("Exit the application"));
    connect(m_exitAction, &QAction::triggered, [=](){ qApp->exit();});

    //viewmenu
    m_viewActionGroup = new QActionGroup(this);
    m_maximizedAction = new QAction("Maximized");
    m_maximizedAction->setCheckable(true);
    m_maximizedAction->setStatusTip(QString("Maximized the view"));
    m_minminizedAction = new QAction("Minminized");
    m_minminizedAction->setCheckable(true);
    m_minminizedAction->setStatusTip(QString("Mininized the view"));
    m_normalAction = new QAction("Normal");
    m_normalAction->setCheckable(true);
    m_normalAction->setStatusTip(QString("Show the normal view"));
    m_toggleFullScreenAction = new QAction("Full Screen");
    m_toggleFullScreenAction->setCheckable(true);
    m_toggleFullScreenAction->setStatusTip(QString("Toggle the view fullscreen"));
    m_viewActionGroup->addAction(m_maximizedAction);
    connect(m_maximizedAction, &QAction::toggled, [=]() { if(m_maximizedAction->isChecked()) showMaximized(); m_lastwindowstate = LastWindowState::L_MAXIMIZED;});
    m_viewActionGroup->addAction(m_minminizedAction);
    connect(m_minminizedAction, &QAction::toggled, [=]() { if(m_minminizedAction->isChecked()){
        switch (m_lastwindowstate) {
        case L_NORMAL:
            m_normalAction->setChecked(true);
            break;
        case L_MAXIMIZED:
            m_maximizedAction->setChecked(true);
            break;
        case L_FULLSCREEN:
            m_toggleFullScreenAction->setChecked(true);
            break;
        default:
            break;
        }
        showMinimized();}
    });
    m_viewActionGroup->addAction(m_normalAction);
    connect(m_normalAction, &QAction::toggled, [=]() { if(m_normalAction->isChecked()) showNormal(); m_lastwindowstate = LastWindowState::L_NORMAL;} );
    m_viewActionGroup->addAction(m_toggleFullScreenAction);
    connect(m_toggleFullScreenAction, &QAction::toggled, [=]() { if(m_toggleFullScreenAction->isChecked()) showFullScreen(); m_lastwindowstate = LastWindowState::L_FULLSCREEN; });
    m_normalAction->setChecked(true);

    //helpmenu
    m_openhelpAction = new QAction("Help");
    m_openhelpAction->setStatusTip(QString("Open the help view"));
    connect(m_openhelpAction, &QAction::triggered, [=]() { HelpView *_helpview = new HelpView(this); _helpview->exec(); });
    m_openAboutViewAction = new QAction("About");
    m_openAboutViewAction->setStatusTip(QString("Open the about view"));
    connect(m_openAboutViewAction, &QAction::triggered, [=]() { AboutView *_aboutview = new AboutView(this); _aboutview->exec(); });
}

void MainWindow::createMenus()
{
    createActions();
    m_mainMenuBar = new QMenuBar(this);
    setMenuBar(m_mainMenuBar);

    m_fileMenu = new QMenu("File", this);
    m_mainMenuBar->addMenu(m_fileMenu);
    m_fileMenu->addAction(m_newfileAction);    
    m_fileMenu->addAction(m_openfileAction);    
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_exitAction);


    m_editMenu = new QMenu("Edit", this);
    m_mainMenuBar->addMenu(m_editMenu);

    m_viewMenu = new QMenu("View", this);
    m_mainMenuBar->addMenu(m_viewMenu);
    m_viewMenu->addAction(m_maximizedAction);
    m_viewMenu->addAction(m_minminizedAction);
    m_viewMenu->addAction(m_normalAction);
    m_viewMenu->addAction(m_toggleFullScreenAction);

    m_helpMenu = new QMenu("Help", this);
    m_mainMenuBar->addMenu(m_helpMenu);
    m_helpMenu->addAction(m_openhelpAction);
    m_helpMenu->addSeparator();
    m_helpMenu->addAction(m_openAboutViewAction);
}

void MainWindow::createToolBar()
{
    m_mainToolBar = new QToolBar("File",this);
    addToolBar(m_mainToolBar);
    m_mainToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    m_TnewfileAction = new QAction(QIcon(":/ToolBarIcons/NewFile.png"), QString("Create New File"), this);
    m_mainToolBar->addAction(m_TnewfileAction);
    m_TopenfileAction = new QAction(QIcon("://ToolBarIcons/file.png"), QString("OpenFile"), this);
    m_mainToolBar->addAction(m_TopenfileAction);
    m_mainToolBar->addSeparator();
    m_searchLineEdit = new SearchLineEdit(this);
    m_searchLineEdit->setFixedWidth(200);
    m_mainToolBar->addWidget(m_searchLineEdit);
    m_toggleFullScreen2Action = new QAction(this);
    m_toggleFullScreen2Action->setIcon(QIcon(":/Basic/full-screen.png"));
    m_mainToolBar->addAction(m_toggleFullScreen2Action);
    connect(m_toggleFullScreen2Action, &QAction::triggered, [=]() {
        if(windowState()!=Qt::WindowFullScreen) {
            m_toggleFullScreenAction->setChecked(true);
            showFullScreen();
            m_lastwindowstate = LastWindowState::L_FULLSCREEN;
        }else{
            m_normalAction->setChecked(true);
            showNormal();
        }
    });
}

void MainWindow::createDockWindows()
{
    m_controlWidget = new QDockWidget("Control Plane", this);
    this->addDockWidget(Qt::TopDockWidgetArea, m_controlWidget);
    m_controlPlaneView = new ControlPlaneView(this);
    m_controlWidget->setWidget(m_controlPlaneView);

    m_fileDockWidget = new QDockWidget("File Browser", this);
    this->addDockWidget(Qt::LeftDockWidgetArea, m_fileDockWidget);
    m_filebrowser = new FileBrowser(this);
    m_fileDockWidget->setWidget(m_filebrowser);

    m_outputDockWidget = new QDockWidget("Output", this);
    this->addDockWidget(Qt::BottomDockWidgetArea, m_outputDockWidget);
    m_outputplane = new OutPutPlane(this);
    m_outputDockWidget->setWidget(m_outputplane);
    m_outputplane->append("Start from: " + qApp->applicationFilePath());
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd");
    m_outputplane->append("Start at " + str);

    m_infoDockWidget = new QDockWidget("Information", this);
    this->addDockWidget(Qt::RightDockWidgetArea, m_infoDockWidget);
    m_informationplae = new InformationPlane(this);
    m_infoDockWidget->setWidget(m_informationplae);
}


