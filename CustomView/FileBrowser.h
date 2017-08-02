#ifndef FILEBROWSER_H
#define FILEBROWSER_H

#include <QWidget>
#include <QLayout>
#include <QDir>
#include <QFileSystemModel>
#include <QTreeView>
#include <QTableView>
#include <QPushButton>
#include <QComboBox>
class FileBrowser : public QWidget
{
    Q_OBJECT
public:
    explicit FileBrowser(QWidget *parent = nullptr);

signals:

public slots:

private:
    void setupUI();
    void initView();
    void initLayout();
    QHBoxLayout *m_buttonLayout;
    QVBoxLayout *m_mainLayout;
    QFileSystemModel *_dirmodel;
    QTreeView *_dirtreeview;
    QComboBox *_dircombobox;
    QPushButton *m_addfileButton;
    QPushButton *m_addfolderButton;
    QPushButton *m_deleteButton;
};

#endif // FILEBROWSER_H
