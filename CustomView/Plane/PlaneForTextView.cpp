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
    m_pasteToolButton = new QToolButton(this);
    m_deleteButton = new QToolButton(this);
    m_printButton = new QToolButton(this);
    m_undoButton = new QToolButton(this);
    m_fontgroupComboBox = new QFontComboBox(this);
    m_fontsizeSpinBox = new QSpinBox(this);
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
    m_pasteToolButton->setIcon(QIcon(":/Basic/TextView/ic_content_paste_white_36dp.png"));
    m_pasteToolButton->setText(QString("Paste"));
    m_pasteToolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_deleteButton->setIcon(QIcon(":/Basic/TextView/ic_delete_white_36dp.png"));
    m_deleteButton->setText(QString("Delete"));
    m_deleteButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_printButton->setIcon(QIcon(":/Basic/TextView/ic_print_white_36dp.png"));
    m_printButton->setText(QString("Print"));
    m_printButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_undoButton->setIcon(QIcon(":/Basic/TextView/ic_undo_white_36dp.png"));
    m_undoButton->setText(QString("Undo"));
    m_undoButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_fontsizeSpinBox->setMaximumWidth(100);
    m_fontsizeSpinBox->setMinimum(6);
    m_fontsizeSpinBox->setMaximum(72);

}

void PlaneForTextView::initLayout()
{
    m_mainlayout = new QHBoxLayout(this);
    this->setLayout(m_mainlayout);
    m_mainlayout->addWidget(m_newfileToolButton);
    m_mainlayout->addWidget(m_openfileToolButton);
    m_mainlayout->addWidget(m_savefileToolButton);
    m_mainlayout->addWidget(m_copyToolButton);
    m_mainlayout->addWidget(m_pasteToolButton);
    m_mainlayout->addWidget(m_deleteButton);
    m_mainlayout->addWidget(m_printButton);
    m_mainlayout->addWidget(m_undoButton);
    m_mainlayout->addSpacing(250);
    m_mainlayout->addWidget(m_fontgroupComboBox);
    m_mainlayout->addWidget(m_fontsizeSpinBox);
}
