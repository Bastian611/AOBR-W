#include "inc/widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    initUI();
    initConnect();
}

Widget::~Widget() {
    m_rtspThread->quit();
    m_rtspThread->exit();
}

void Widget::initUI() {
    this->resize(960, 540);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(5, 10, 5, 5);

    QHBoxLayout *inputLayout = new QHBoxLayout();
    m_urlEdit = new QLineEdit(this);
    inputLayout->addWidget(m_urlEdit);
    m_startBtn = new QPushButton("点播", this);
    inputLayout->addWidget(m_startBtn);
    m_stopBtn = new QPushButton("停止", this);
    inputLayout->addWidget(m_stopBtn);

    m_glWidget = new MyGLWidget(this);

    mainLayout->addLayout(inputLayout);
    mainLayout->addWidget(m_glWidget);
    this->setLayout(mainLayout);

    m_rtspThread = new Rtsp();
}

void Widget::initConnect() {
    connect(m_rtspThread, &Rtsp::sigYuv, m_glWidget, &MyGLWidget::showYuv);
    connect(m_startBtn, &QPushButton::clicked, [this]() {
        m_rtspThread->setMediaUrl(m_urlEdit->text());
        m_rtspThread->start();
    });
    connect(m_stopBtn, &QPushButton::clicked, [this]() {
        m_rtspThread->requestInterruption();
        m_rtspThread->quit();
        m_rtspThread->wait();
        m_glWidget->update();
    });
}

