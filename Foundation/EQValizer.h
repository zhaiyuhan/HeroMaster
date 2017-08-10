#ifndef EQVALIZER_H
#define EQVALIZER_H

#include <QWidget>
#include <QSlider>
#include <QRadioButton>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
class EQValizer : public QWidget
{
    Q_OBJECT
public:
    explicit EQValizer(QWidget *parent = nullptr);

signals:

public slots:

private:
    void setupUI();
    void initLayout();
    void initUI();
    QVBoxLayout *m_mainlayout;
    QHBoxLayout *buttonlayout;
    QHBoxLayout *sliderlayout;
    QRadioButton *m_oneqRadioButton;
    QPushButton *m_resettingButton;
    QPushButton *m_preinstallButton;
    QSlider *slider[10];
};

#endif // EQVALIZER_H
