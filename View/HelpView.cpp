#include "HelpView.h"
#include "ui_HelpView.h"
#include <QDesktopServices>
#include <QUrl>
#include "Foundation/CustomShadowEffect.h"
HelpView::HelpView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpView)
{
    ui->setupUi(this);
    CustomShadowEffect *bodyShadow = new CustomShadowEffect();
    bodyShadow->setBlurRadius(50.0);
    bodyShadow->setDistance(10.0);
    bodyShadow->setColor(QColor(21, 25, 30, 80));
    ui->label_7->setAutoFillBackground(true);
    ui->label_7->setGraphicsEffect(bodyShadow);
}

HelpView::~HelpView()
{
    delete ui;
}

void HelpView::on_label_linkActivated(const QString &link)
{
    QDesktopServices::openUrl(QUrl(link));
}
