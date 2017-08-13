#ifndef CUSTOMMIDSUBWINDOW_H
#define CUSTOMMIDSUBWINDOW_H

#include <QWidget>
#include <QMdiSubWindow>
#include <QPaintEvent>
#include <QPainter>
class CustomMidSubWindow : public QMdiSubWindow
{
    Q_OBJECT
public:
    explicit CustomMidSubWindow(QWidget *parent = nullptr);

signals:

public slots:
protected:
    void paintEvent(QPaintEvent);
};

#endif // CUSTOMMIDSUBWINDOW_H
