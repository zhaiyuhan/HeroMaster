#ifndef FULLVIEWPLANE_H
#define FULLVIEWPLANE_H

#include <QWidget>
#include <QGroupBox>
#include <QProgressBar>
#include <QVBoxLayout>
#include "Foundation/EQValizer.h"
class FullViewPlane : public QWidget
{
    Q_OBJECT
public:
    explicit FullViewPlane(QWidget *parent = nullptr);

signals:

public slots:

private:
    void setupUI();
    void initLayout();
    void initUI();

    QGroupBox *visualViewGroupBox;
    QGroupBox *eqvalizerGroupBox;
    QProgressBar *m_progressbar;
    QVBoxLayout *m_mainlayout;
    EQValizer *eqvalizer;
};

#endif // FULLVIEWPLANE_H
