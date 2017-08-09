#ifndef CONTROLPLANEVIEW_H
#define CONTROLPLANEVIEW_H

#include <QWidget>
#include <QComboBox>
#include <QStackedWidget>
#include <QHBoxLayout>
#include "CustomView/Plane/PlaneForTextView.h"
#include "CustomView/Plane/PlaneForAudioPlane.h"
#include "CustomView/Plane/PlaneForVideoView.h"
#include "CustomView/Plane/PlaneForCameraView.h"

class ControlPlaneView : public QWidget
{
    Q_OBJECT
public:
    explicit ControlPlaneView(QWidget *parent = nullptr);

signals:

public slots:

private:
    void setupUI();
    void initLayout();
    void initUI();
    QHBoxLayout *m_mainlayout;
    QStackedWidget *m_mainStackedWidget;
    PlaneForTextView *m_PlaneForTextView;
    PlaneForAudioPlane *m_PlaneForAudioPlane;
    PlaneForVideoView *m_PlaneForVideoView;
    PlaneForCameraView *m_PlaneForCameraView;
    QComboBox *m_selectplaneComboBox;
};

#endif // CONTROLPLANEVIEW_H
