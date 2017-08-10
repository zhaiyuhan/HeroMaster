#include "EQValizer.h"

EQValizer::EQValizer(QWidget *parent) : QWidget(parent)
{
    initUI();
}

void EQValizer::setupUI()
{
    m_oneqRadioButton = new QRadioButton(QString("ON"), this);
    m_resettingButton = new QPushButton(QString("Resetting"), this);
    m_resettingButton->setFixedWidth(80);
    m_preinstallButton = new QPushButton(QString("Preinstall"), this);
    m_preinstallButton->setFixedWidth(80);
}

void EQValizer::initLayout()
{
    m_mainlayout = new QVBoxLayout(this);
    setLayout(m_mainlayout);
    buttonlayout = new QHBoxLayout();
    buttonlayout->addWidget(m_oneqRadioButton);
    buttonlayout->addWidget(m_resettingButton);
    buttonlayout->addWidget(m_preinstallButton);
    m_mainlayout->addLayout(buttonlayout);
    sliderlayout = new QHBoxLayout();
    for(int i = 0 ; i < 10 ; i++){
        slider[i] = new QSlider(Qt::Vertical, this);
        sliderlayout->addWidget(slider[i]);
    }
    m_mainlayout->addLayout(sliderlayout);

}

void EQValizer::initUI()
{
    setupUI();
    initLayout();
}
