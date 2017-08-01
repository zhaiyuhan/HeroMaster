#include "AboutView.h"
#include "ui_AboutView.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
AboutView::AboutView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutView)
{
    ui->setupUi(this);
    QString filename = QString(":/AboutView/AboutView/About.html");
    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Application Error", tr("Cannot read file %1:\n%2.").arg(filename).arg(file.errorString()));
         return;
    }
    QTextStream in(&file);
    ui->textBrowser->insertHtml(in.readAll());
    connect(ui->pushButton, &QPushButton::clicked, [=]() { this->close();});
}

AboutView::~AboutView()
{
    delete ui;
}
