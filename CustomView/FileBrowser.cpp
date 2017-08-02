#include "FileBrowser.h"

FileBrowser::FileBrowser(QWidget *parent) : QWidget(parent)
{
    initView();
}

void FileBrowser::setupUI()
{
    m_addfileButton = new QPushButton("Add File", this);
    m_addfileButton->setFixedHeight(25);
    m_addfolderButton = new QPushButton("Add Folder", this);
    m_addfolderButton->setFixedHeight(25);
    m_deleteButton = new QPushButton("Delete", this);
    m_deleteButton->setFixedHeight(25);
    _dirmodel = new QFileSystemModel(this);
    _dirtreeview = new QTreeView(this);
    _dircombobox = new QComboBox;
    _dircombobox->setFixedHeight(20);
    _dirmodel->setRootPath(QDir::currentPath());
    _dirtreeview->setModel(_dirmodel);
}

void FileBrowser::initView()
{
    setupUI();
    initLayout();
}

void FileBrowser::initLayout()
{
    m_mainLayout = new QVBoxLayout();
    m_buttonLayout = new QHBoxLayout();
    m_mainLayout->addWidget(_dircombobox);
    m_mainLayout->addWidget(_dirtreeview);
    m_buttonLayout->addWidget(m_addfileButton);
    m_buttonLayout->addWidget(m_addfolderButton);
    m_buttonLayout->addWidget(m_deleteButton);
    m_mainLayout->addLayout(m_buttonLayout);
    this->setLayout(m_mainLayout);
}
