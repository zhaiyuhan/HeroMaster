#ifndef INFORMATIONPLANE_H
#define INFORMATIONPLANE_H

#include <QWidget>
#include <QTreeWidget>

class InformationPlane : public QTreeWidget
{
    Q_OBJECT
public:
    explicit InformationPlane(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // INFORMATIONPLANE_H
