#include "ControlPlaneView.h"
ControlPlaneView::ControlPlaneView(QWidget *parent) : QWidget(parent)
{
    setFixedHeight(60);
    initUI();
    connect(m_selectplaneComboBox, SIGNAL(currentIndexChanged(int)), m_mainStackedWidget, SLOT(setCurrentIndex(int)));
}

void ControlPlaneView::playmusic(QString _filename)
{
    m_PlaneForAudioPlane->setFileName(_filename);
}

void ControlPlaneView::setupUI()
{    
    m_mainStackedWidget = new QStackedWidget(this);
    m_PlaneForTextView = new PlaneForTextView(this);
    m_PlaneForAudioPlane = new PlaneForAudioPlane(this);
    m_PlaneForVideoView = new PlaneForVideoView(this);
    m_PlaneForCameraView = new PlaneForCameraView(this);   
    m_selectplaneComboBox = new QComboBox(this);   
}

void ControlPlaneView::initLayout()
{
    m_mainlayout = new QHBoxLayout(this);
    m_mainlayout->setMargin(0);
    this->setLayout(m_mainlayout);
    m_mainlayout->addWidget(m_mainStackedWidget);
    m_mainlayout->addWidget(m_selectplaneComboBox);
}

void ControlPlaneView::initUI()
{
    setupUI();
    initLayout();
    m_mainStackedWidget->setObjectName(QString::fromUtf8("controlplane"));
    m_mainStackedWidget->addWidget(m_PlaneForTextView);
    m_mainStackedWidget->addWidget(m_PlaneForAudioPlane);
    m_mainStackedWidget->addWidget(m_PlaneForVideoView);
    m_mainStackedWidget->addWidget(m_PlaneForCameraView);
    m_selectplaneComboBox->insertItem(0, "Text");
    m_selectplaneComboBox->insertItem(1, "Audio");
    m_selectplaneComboBox->insertItem(2, "Video");
    m_selectplaneComboBox->insertItem(3, "Camera");
    m_selectplaneComboBox->setFixedSize(100, 30);
}
