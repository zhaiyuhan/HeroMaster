#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>
#include <QFile>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
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
    QStackedWidget *m_mainStackedWidget;
    QPushButton *m_textviewButton;
    QPushButton *m_audioviewButton;
    QPushButton *m_videoviewButton;
    QPushButton *m_cameraviewButton;
};

#endif // MAINVIEW_H
