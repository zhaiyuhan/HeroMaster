#include "CustomMidSubWindow.h"

CustomMidSubWindow::CustomMidSubWindow(QWidget *parent) : QMdiSubWindow(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
     setAttribute(Qt::WA_TranslucentBackground);
}

void CustomMidSubWindow::paintEvent(QPaintEvent)
{
        QPainter painter(this);
            painter.setPen(Qt::NoPen);
            painter.setBrush(Qt::white);
            painter.setRenderHint(QPainter::Antialiasing, true);
            painter.drawRoundedRect(0, 3, width(), height(), 5, 5);
}
