#ifndef AUDIOVIEW_H
#define AUDIOVIEW_H

#include <QWidget>
#include <QTabWidget>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QListWidget>
#include "CustomView/Plane/FullViewPlane.h"
class AudioView : public QWidget
{
    Q_OBJECT
public:
    explicit AudioView(QWidget *parent = nullptr);

signals:

public slots:

private:
    void setupUI();
    void initLayout();
    void initUI();
    QHBoxLayout *m_mainlayout;
    QListWidget *m_mainlistListWidget;
    QTabWidget *m_mainTabWidget;

    FullViewPlane *fullviewplane;
};

#endif // AUDIOVIEW_H
