#ifndef SEARCHLINEEDIT_H
#define SEARCHLINEEDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QAction>
class SearchLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit SearchLineEdit(QWidget *parent = nullptr);
    QAction *searchAction;
signals:

public slots:
};

#endif // SEARCHLINEEDIT_H
