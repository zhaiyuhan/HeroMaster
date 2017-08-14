#include "TextView.h"

TextView::TextView(QWidget *parent) : QMdiArea(parent)
{

    CustomMidSubWindow *child = new CustomMidSubWindow();
    this->addSubWindow(child);
    child->move(20,20);
    child->resize(400,200);
    child->show();

}
