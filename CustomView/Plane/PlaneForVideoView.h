#ifndef PLANEFORVIDEOVIEW_H
#define PLANEFORVIDEOVIEW_H

#include <QWidget>
#include <QToolButton>
#include <QSlider>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
class PlaneForVideoView : public QWidget
{
    Q_OBJECT
public:
    explicit PlaneForVideoView(QWidget *parent = nullptr);

signals:

public slots:

private:
    void setupUI();
    void initUI();
    void initLayout();
    QVBoxLayout *m_mainlayout;
    QHBoxLayout *m_controllayout;
    QSlider *m_progreeSlider;
    QToolButton *playButton;
    QToolButton *volumeButton;
    QLabel *timeLabel;
    QToolButton *listButton;
    QToolButton *fullscreenButton;
};

#endif // PLANEFORVIDEOVIEW_H
