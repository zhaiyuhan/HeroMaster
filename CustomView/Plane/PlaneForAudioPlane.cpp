#include "PlaneForAudioPlane.h"

PlaneForAudioPlane::PlaneForAudioPlane(QWidget *parent) : QWidget(parent)
{
    initUI();
}

void PlaneForAudioPlane::setupUI()
{
    previousButton = new QPushButton(this);
    playButton = new QPushButton(this);
    nextButton = new QPushButton(this);
    volumeSlider = new QSlider(Qt::Horizontal, this);
    ImageButton = new QPushButton(this);
    currenttimeLabel = new QLabel(this);
    titleLabel = new QLabel(this);
    totalTimeLabel = new QLabel(this);
    progressSlider = new QSlider(Qt::Horizontal, this);
}

void PlaneForAudioPlane::initLayout()
{
    m_mainlayout = new QHBoxLayout(this);
    m_mainlayout->setMargin(0);
    //this->setLayout(m_mainlayout);
    m_mainlayout->addWidget(previousButton);
    m_mainlayout->addWidget(playButton);
    m_mainlayout->addWidget(nextButton);
    m_mainlayout->addWidget(volumeSlider);
    m_mainlayout->addWidget(ImageButton);
    gridlayout = new QGridLayout(this);
    m_mainlayout->addLayout(gridlayout);
    currenttimeLabel->setText(QString("CurrentTime"));
    titleLabel->setText(QString("Title"));
    totalTimeLabel->setText(QString("TotalTime"));
    gridlayout->addWidget(currenttimeLabel, 0, 0, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);
    gridlayout->addWidget(titleLabel, 0, 1, 1, 1, Qt::AlignCenter | Qt::AlignVCenter);
    gridlayout->addWidget(totalTimeLabel, 0, 2, 1, 1, Qt::AlignRight | Qt::AlignVCenter);
    gridlayout->addWidget(progressSlider, 1, 0, 3, 3, Qt::AlignVCenter);

}

void PlaneForAudioPlane::initUI()
{
    setupUI();
    initLayout();
    previousButton->setFixedSize(50, 50);
    previousButton->setIconSize(QSize(30, 30));
    previousButton->setIcon(QIcon(":/Basic/previous.png"));
    playButton->setFixedSize(50, 50);
    playButton->setIconSize(QSize(30 ,30));
    playButton->setIcon(QIcon(":/Basic/play.png"));
    nextButton->setFixedSize(50, 50);
    nextButton->setIconSize(QSize(30, 30));
    nextButton->setIcon(QIcon(":/Basic/next.png"));
    volumeSlider->setFixedWidth(120);
    ImageButton->setFixedSize(QSize(60, 60));
}
