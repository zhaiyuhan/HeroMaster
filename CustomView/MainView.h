#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>
#include <QFile>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "CustomView/TextView.h"
#include "CustomView/AudioView.h"
class MainView : public QWidget
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = nullptr);

signals:

public slots:
private:
    void setupUI();
    void initView();
    void initLayout();
    QVBoxLayout *m_mainlayout;
    QHBoxLayout *m_buttonlayout;
    QVBoxLayout *mainlayout;
    QStackedWidget *m_mainStackedWidget;
    QPushButton *m_textviewButton;
    QPushButton *m_audioviewButton;
    QPushButton *m_videoviewButton;
    QPushButton *m_cameraviewButton;

    TextView *m_textview;
    AudioView *m_audioview;
};

#endif // MAINVIEW_H
