#include "InformationPlane.h"

InformationPlane::InformationPlane(QWidget *parent) : QTreeWidget(parent)
{
    setColumnCount(1); //设置列数
    setHeaderLabel(QString("Text information")); //设置头的标题

    QTreeWidgetItem *imageItem1 = new QTreeWidgetItem(this,QStringList(QString("File Information")));
    QTreeWidgetItem *imageItem1_2 = new QTreeWidgetItem(imageItem1,QStringList(QString("File Name")));
    QTreeWidgetItem *imageItem1_3 = new QTreeWidgetItem(imageItem1,QStringList(QString("File Path")));
    QTreeWidgetItem *imageItem1_4 = new QTreeWidgetItem(imageItem1,QStringList(QString("File Size")));
    imageItem1->addChild(imageItem1_2);
    imageItem1->addChild(imageItem1_3);
    imageItem1->addChild(imageItem1_4);
    QTreeWidgetItem *imageItem2 = new QTreeWidgetItem(this,QStringList(QString("Test")));
    QTreeWidgetItem *imageItem2_1 = new QTreeWidgetItem(imageItem2,QStringList(QString("Band1")));
    QTreeWidgetItem *imageItem2_2 = new QTreeWidgetItem(imageItem2,QStringList(QString("Band2")));
    imageItem2->addChild(imageItem2_1);  //添加子节点
    imageItem2->addChild(imageItem2_2);

    expandAll(); //结点全部展开
}
