#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QDesktopWidget>
#include <QDockWidget>
#include <QToolBar>
#include <QMenuBar>
#include <QMenu>
#include <QStatusBar>
#include <QPushButton>
#include <QLabel>
#include <QActionGroup>
#include <QAction>
#include <QLayout>
#include <QEvent>
#include <QShowEvent>

#include "View/AboutView/AboutView.h"
#include "View/HelpView.h"
#include "CustomView/MainView.h"
#include "CustomView/FileBrowser.h"
#include "CustomView/Plane/OutPutPlane.h"
#include "CustomView/Plane/InformationPlane.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void setupUI();
    void initUI();
    void createActions();
    void createMenus();
    void createToolBar();
    void createDockWindows();

    QMenuBar *m_mainMenuBar;    
    QMenu *m_fileMenu;
    QAction *m_newfileAction;
    QAction *m_openfileAction;
    QAction *m_exitAction;
    QMenu *m_editMenu;

    QMenu *m_viewMenu;
    QActionGroup *m_viewActionGroup;
    QAction *m_maximizedAction;
    QAction *m_minminizedAction;
    QAction *m_normalAction;
    QAction *m_toggleFullScreenAction;

    QMenu *m_helpMenu;
    QAction *m_openhelpAction;
    QAction *m_openAboutViewAction;

    QToolBar *m_mainToolBar;
    QAction *m_TnewfileAction;
    QAction *m_TopenfileAction;

    QPushButton *m_ConsoleButton;

    enum LastWindowState{
        L_NORMAL,
        L_MIINIMIZED,
        L_MAXIMIZED,
        L_FULLSCREEN
    };
    LastWindowState m_lastwindowstate;

    MainView *m_mainview;
    QDockWidget *m_fileDockWidget;
    QDockWidget *m_infoDockWidget;
    QDockWidget *m_outputDockWidget;

    FileBrowser *m_filebrowser;
    OutPutPlane *m_outputplane;
    InformationPlane *m_informationplae;

};

#endif // MAINWINDOW_H
