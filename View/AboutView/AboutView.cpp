#include "AboutView.h"
#include "ui_AboutView.h"
//#include <QFile>
//#include <QTextStream>
//#include <QMessageBox>
AboutView::AboutView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutView)
{
    ui->setupUi(this);
    /*QString filename = QString(":/AboutView/AboutView/About.html");
    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Application Error", tr("Cannot read file %1:\n%2.").arg(filename).arg(file.errorString()));
         return;
    }
    QTextStream in(&file);
    ui->textBrowser->insertHtml(in.readAll());*/
    ui->textBrowser->setSource(QUrl("qrc:/AboutView/AboutView/About.html"));
    connect(ui->pushButton, &QPushButton::clicked, [=]() { this->close();});
    CustomShadowEffect *bodyShadow = new CustomShadowEffect();
    bodyShadow->setBlurRadius(20.0);
    bodyShadow->setDistance(6.0);
    bodyShadow->setColor(QColor(21, 25, 30, 60));
    ui->textBrowser->setAutoFillBackground(true);
    ui->textBrowser->setGraphicsEffect(bodyShadow);
}

AboutView::~AboutView()
{
    delete ui;
}
