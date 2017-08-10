#include "FullViewPlane.h"

FullViewPlane::FullViewPlane(QWidget *parent) : QWidget(parent)
{
    initUI();
}

void FullViewPlane::setupUI()
{
    visualViewGroupBox = new QGroupBox(QString("Visual View"), this);
    eqvalizerGroupBox = new QGroupBox(QString("EQVALIZER"), this);
    eqvalizer = new EQValizer(this);
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(eqvalizer);
    eqvalizerGroupBox->setLayout(layout);
    m_progressbar = new QProgressBar(this);
}

void FullViewPlane::initLayout()
{
    m_mainlayout = new QVBoxLayout(this);
    this->setLayout(m_mainlayout);
    m_mainlayout->setMargin(2);
    m_mainlayout->addWidget(visualViewGroupBox);
    m_mainlayout->addWidget(eqvalizerGroupBox);
    m_mainlayout->addWidget(m_progressbar);
}

void FullViewPlane::initUI()
{
    setupUI();
    initLayout();
    m_progressbar->setValue(50);
}
