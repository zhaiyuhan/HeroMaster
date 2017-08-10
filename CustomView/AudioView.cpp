#include "AudioView.h"

AudioView::AudioView(QWidget *parent) : QWidget(parent)
{
    initUI();
}

void AudioView::setupUI()
{
    m_mainlistListWidget = new QListWidget(this);
    m_mainTabWidget = new QTabWidget(this);

    fullviewplane = new FullViewPlane(this);
}

void AudioView::initLayout()
{
    m_mainlayout = new QHBoxLayout(this);
    setLayout(m_mainlayout);
    m_mainlayout->setMargin(5);
    m_mainlayout->addWidget(m_mainlistListWidget);
    m_mainlayout->addWidget(m_mainTabWidget);

}

void AudioView::initUI()
{
    setupUI();
    initLayout();
    m_mainlistListWidget->setFixedWidth(200);
    QWidget *m1 = new QWidget;
    m_mainTabWidget->addTab(m1, "List View");
    m_mainTabWidget->addTab(fullviewplane, "Full View");
}
