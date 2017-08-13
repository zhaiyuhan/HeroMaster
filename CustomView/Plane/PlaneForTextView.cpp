#include "PlaneForTextView.h"

PlaneForTextView::PlaneForTextView(QWidget *parent) : QWidget(parent)
{
    initUI();

}

void PlaneForTextView::setupUI()
{
    m_newfileToolButton = new QToolButton(this);
    m_openfileToolButton = new QToolButton(this);
    m_savefileToolButton = new QToolButton(this);
    m_copyToolButton = new QToolButton(this);
}

void PlaneForTextView::initUI()
{
    setupUI();
    initLayout();
    m_newfileToolButton->setIcon(QIcon(":/Basic/TextView/new-file.png"));
    m_newfileToolButton->setText(QString("New File"));
    m_newfileToolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_openfileToolButton->setIcon(QIcon(":/Basic/TextView/icon_file_open.png"));
    m_openfileToolButton->setText(QString("Open File"));
    m_openfileToolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_savefileToolButton->setIcon(QIcon(":/Basic/TextView/save-file-option.png"));
    m_savefileToolButton->setText(QString("Save File"));
    m_savefileToolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_copyToolButton->setIcon(QIcon(":/Basic/TextView/ic_content_copy_white_36dp.png"));
    m_copyToolButton->setText(QString("Copy"));
    m_copyToolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

}

void PlaneForTextView::initLayout()
{
    m_mainlayout = new QHBoxLayout(this);
    this->setLayout(m_mainlayout);
    m_mainlayout->addWidget(m_newfileToolButton);
    m_mainlayout->addWidget(m_openfileToolButton);
    m_mainlayout->addWidget(m_savefileToolButton);
    m_mainlayout->addWidget(m_copyToolButton);
}
