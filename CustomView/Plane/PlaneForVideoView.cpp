#include "PlaneForVideoView.h"

PlaneForVideoView::PlaneForVideoView(QWidget *parent) : QWidget(parent)
{
    initUI();
}

void PlaneForVideoView::setupUI()
{
    m_progreeSlider = new QSlider(Qt::Horizontal, this);
    playButton = new QToolButton(this);
    volumeButton = new QToolButton(this);
    timeLabel = new QLabel(this);
    listButton = new QToolButton(this);
    fullscreenButton = new QToolButton(this);
}

void PlaneForVideoView::initUI()
{
    setupUI();
    initLayout();
    playButton->setIconSize(QSize(64, 64));
    playButton->setIcon(QIcon(":/Basic/VideoView/ic_play_arrow_white_48dp.png"));
    volumeButton->setIcon(QIcon(":/Basic/VideoView/ic_volume_up_white_36dp.png"));
    timeLabel->setText(QString("00:00/00:00"));
    listButton->setIcon(QIcon(":/Basic/VideoView/ic_list_white_36dp.png"));
    fullscreenButton->setIcon(QIcon(":/Basic/VideoView/ic_fullscreen_white_36dp.png"));
}

void PlaneForVideoView::initLayout()
{
    m_mainlayout = new QVBoxLayout(this);
    this->setLayout(m_mainlayout);
    m_mainlayout->setContentsMargins(QMargins(10, 2, 10, 1));
    m_mainlayout->addWidget(m_progreeSlider);
    m_controllayout = new QHBoxLayout();
    m_mainlayout->addLayout(m_controllayout);
    m_controllayout->addWidget(playButton, Qt::AlignLeft);
    m_controllayout->addWidget(volumeButton, Qt::AlignLeft);
    m_controllayout->addWidget(timeLabel, Qt::AlignLeft);
    m_controllayout->addWidget(listButton, Qt::AlignRight);
    m_controllayout->addWidget(fullscreenButton, Qt::AlignRight);
}


