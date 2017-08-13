#ifndef PLANEFORTEXTVIEW_H
#define PLANEFORTEXTVIEW_H

#include <QWidget>
#include <QToolButton>
#include <QHBoxLayout>
#include <QMdiArea>
#include <QMdiSubWindow>
class PlaneForTextView : public QWidget
{
    Q_OBJECT
public:
    explicit PlaneForTextView(QWidget *parent = nullptr);

signals:

public slots:

private:
    void setupUI();
    void initUI();
    void initLayout();
    QHBoxLayout *m_mainlayout;
    QToolButton *m_newfileToolButton;
    QToolButton *m_openfileToolButton;
    QToolButton *m_savefileToolButton;
    QToolButton *m_copyToolButton;

};

#endif // PLANEFORTEXTVIEW_H
