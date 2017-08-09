#ifndef PLANEFORAUDIOPLANE_H
#define PLANEFORAUDIOPLANE_H

#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QHBoxLayout>
#include <QGridLayout>

class PlaneForAudioPlane : public QWidget
{
public:
    explicit PlaneForAudioPlane(QWidget *parent = nullptr);
private:
    void setupUI();
    void initLayout();
    void initUI();
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
};

#endif // PLANEFORAUDIOPLANE_H
