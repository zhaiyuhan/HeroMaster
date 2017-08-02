#include "HelpView.h"
#include "ui_HelpView.h"

HelpView::HelpView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpView)
{
    ui->setupUi(this);
}

HelpView::~HelpView()
{
    delete ui;
}
