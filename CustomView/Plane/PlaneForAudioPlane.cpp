#include "PlaneForAudioPlane.h"

PlaneForAudioPlane::PlaneForAudioPlane(QWidget *parent) : QWidget(parent)
{
    initUI();
    initEvents();
}

void PlaneForAudioPlane::setFileName(QString _filename)
{
    m_filename = _filename;
    play(m_filename);
    QStringList info;
    if (!m_filename.isEmpty())
        info.append(m_filename);
    if (player->isMetaDataAvailable()) {
        QString author = player->metaData(QStringLiteral("Author")).toString();
        if (!author.isEmpty())
            info.append(author);
        QString title = player->metaData(QStringLiteral("Title")).toString();
        if (!title.isEmpty())
            info.append(title);
    }
    titleLabel->setText(info.join(tr(" - ")));
    update();

}

void PlaneForAudioPlane::play(QString _filename)
{
    player->setMedia(QUrl::fromLocalFile(_filename));
    player->play();
    playButton->setIcon(QIcon(":/Basic/pause.png"));
}

void PlaneForAudioPlane::play()
{
    switch (player->state()) {
    case QMediaPlayer::State::PlayingState:
        player->pause();
        playButton->setIcon(QIcon(":/Basic/play.png"));
        break;
    case QMediaPlayer::State::PausedState:
        player->play();
        playButton->setIcon(QIcon(":/Basic/pause.png"));
        break;
    default:
        break;
    }
}

void PlaneForAudioPlane::setVolume(int _volume)
{
    player->setVolume(_volume);
}

void PlaneForAudioPlane::posChanged(qint64 pos)
{
    progressSlider->setValue(pos);
    QString presentTime;
    pos/=1000;
    presentTime+=QString::number(pos/60);
    presentTime+=':';
    if(pos%60<10)
        presentTime+='0';
    presentTime+=QString::number(pos%60);
    currenttimeLabel->setText(presentTime);

}

void PlaneForAudioPlane::durChanged(qint64 dur)
{
    progressSlider->setRange(0, dur);
    QString totalTime;
    dur/=1000;
    totalTime+=QString::number(dur/60);
    totalTime+=':';
    if(dur%60<10)
        totalTime+='0';
    totalTime+=QString::number(dur%60);
    totalTimeLabel->setText(totalTime);
}

void PlaneForAudioPlane::setPos(int pos)
{
    player->setPosition(pos);
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
    player = new QMediaPlayer(this);
}

void PlaneForAudioPlane::initLayout()
{
    m_mainlayout = new QHBoxLayout(this);
    m_mainlayout->setMargin(0);
    this->setLayout(m_mainlayout);
    m_mainlayout->addWidget(previousButton);
    m_mainlayout->addWidget(playButton);
    m_mainlayout->addWidget(nextButton);
    m_mainlayout->addWidget(volumeSlider);
    m_mainlayout->addWidget(ImageButton);
    gridlayout = new QGridLayout();
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
    volumeSlider->setValue(100);
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

void PlaneForAudioPlane::initEvents()
{
    connect(playButton, &QPushButton::clicked, [=]() { play(); });
    connect(volumeSlider, &QSlider::valueChanged, [=](int v) { setVolume(v); } );
    connect(player, &QMediaPlayer::durationChanged, [=](qint64 d) { durChanged(d); });
    connect(player, &QMediaPlayer::positionChanged, [=](qint64 p) { posChanged(p); });
    connect(progressSlider, &QSlider::valueChanged, [=](int p) { setPos(p); });
}
