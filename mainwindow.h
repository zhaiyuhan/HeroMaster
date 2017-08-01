#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QDesktopWidget>
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
    QAction *m_openAboutViewAction;

    QToolBar *m_mainToolBar;
    QAction *m_TnewfileAction;
    QAction *m_TopenfileAction;

    QPushButton *m_ConsoleButton;
    QLabel *m_tooltipLabel;

    enum LastWindowState{
        L_NORMAL,
        L_MIINIMIZED,
        L_MAXIMIZED,
        L_FULLSCREEN
    };
    LastWindowState m_lastwindowstate;
};

#endif // MAINWINDOW_H
