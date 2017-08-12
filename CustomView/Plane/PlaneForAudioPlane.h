#ifndef PLANEFORAUDIOPLANE_H
#define PLANEFORAUDIOPLANE_H

#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QHBoxLayout>
#include <QGridLayout>

#include <QMediaPlayer>
#include <QMediaPlaylist>

#include <QUrl>
class PlaneForAudioPlane : public QWidget
{
public:
    explicit PlaneForAudioPlane(QWidget *parent = nullptr);

    void setFileName(QString _filename);

private slots:
    void addSongs();
    void play(QString _filename);
    void play();
    void setVolume(int _volume);
    void posChanged(qint64 pos);
    void durChanged(qint64 dur);
    void setPos(int pos);

private:
    void setupUI();
    void initLayout();
    void initUI();
    void initEvents();
    QHBoxLayout *m_mainlayout;
    QGridLayout *gridlayout;

    QPushButton *previousButton;
    QPushButton *playButton;
    QPushButton *nextButton;
    QSlider *volumeSlider;
    QPushButton *ImageButton;
    QLabel *currenttimeLabel;
    QLabel *titleLabel;
    QLabel *totalTimeLabel;
    QSlider *progressSlider;

    QMediaPlayer *player;

    QString m_filename;
};

#endif // PLANEFORAUDIOPLANE_H
