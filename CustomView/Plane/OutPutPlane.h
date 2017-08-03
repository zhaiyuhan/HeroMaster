#ifndef OUTPUTPLANE_H
#define OUTPUTPLANE_H

#include <QWidget>
#include <QTextEdit>
#include <QDateTime>
class OutPutPlane : public QTextEdit
{
public:
    explicit OutPutPlane(QWidget *parent = 0);
};

#endif // OUTPUTPLANE_H
