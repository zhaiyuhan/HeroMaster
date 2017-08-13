#ifndef TEXTVIEW_H
#define TEXTVIEW_H

#include <QWidget>
#include <QMdiArea>
#include <QTextEdit>

#include "Foundation/CustomMidSubWindow.h"
class TextView : public QMdiArea
{
    Q_OBJECT
public:
    explicit TextView(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // TEXTVIEW_H
