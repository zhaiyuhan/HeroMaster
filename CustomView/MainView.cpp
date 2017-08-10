#include "MainView.h"

MainView::MainView(QWidget *parent) : QWidget(parent)
{
    initView();
}

void MainView::setupUI()
{
    m_textviewButton = new QPushButton("Text View", this);
    m_textviewButton->setFixedSize(150, 30);
    m_audioviewButton = new QPushButton("Audio View", this);
    m_audioviewButton->setFixedSize(150, 30);
    m_videoviewButton = new QPushButton("Video View", this);
    m_videoviewButton->setFixedSize(150, 30);
    m_cameraviewButton = new QPushButton("Camera View", this);
    m_cameraviewButton->setFixedSize(150, 30);
    m_mainStackedWidget = new QStackedWidget(this);
    m_audioview = new AudioView(this);
    m_mainStackedWidget->addWidget(m_audioview);
}

void MainView::initView()
{
    setupUI();
    initLayout();
}

void MainView::initLayout()
{
    m_mainlayout = new QVBoxLayout();
    this->setLayout(m_mainlayout);
    m_buttonlayout = new QHBoxLayout();
    m_buttonlayout->setSpacing(5);
    m_buttonlayout->setAlignment(m_mainlayout, Qt::AlignCenter);
    m_mainlayout->addLayout(m_buttonlayout);
    m_mainlayout->addWidget(m_mainStackedWidget);
    m_mainlayout->setSpacing(5);
    m_buttonlayout->addWidget(m_textviewButton);
    m_buttonlayout->addWidget(m_audioviewButton);
    m_buttonlayout->addWidget(m_videoviewButton);
    m_buttonlayout->addWidget(m_cameraviewButton);    
}
