#include "inc/QDaulLightCamera.h"
#include "../ui_QDaulLightCamera.h"

QDaulLightCamera::QDaulLightCamera(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QDaulLightCamera)
{
    createContext();
    Init();
    connections();
    ui->setupUi(this);
}

QDaulLightCamera::~QDaulLightCamera()
{
    destroyContext();
    delete ui;
}

void QDaulLightCamera::createContext()
{
    // destroyContext();
    m_rtspThread = new Rtsp();
}

void QDaulLightCamera::Init()
{
    // this->resize(550, 490);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(5, 10, 5, 5);

    QHBoxLayout *inputLayout = new QHBoxLayout();
    m_pbMainStream = new QPushButton("主码流", this);
    inputLayout->addWidget(m_pbMainStream);
    m_pbSubStream = new QPushButton("子码流", this);
    inputLayout->addWidget(m_pbSubStream);
    // m_pbStartPlay = new QPushButton("开始播放", this);
    // inputLayout->addWidget(m_pbStartPlay);
    // m_pbStopPlay = new QPushButton("停止播放", this);
    // inputLayout->addWidget(m_pbStopPlay);

    m_glWidget = new MyGLWidget(this);

    mainLayout->addWidget(m_glWidget);
    mainLayout->addLayout(inputLayout);
    this->setLayout(mainLayout);

    m_pbMainStream->setEnabled(false);
    m_pbSubStream->setEnabled(true);
    m_sUrl = "rtsp://admin:admin123@192.168.1.64:554/PSIA/streaming/channels/101";
}

void QDaulLightCamera::destroyContext()
{
    if(m_rtspThread)
    {
        m_rtspThread->quit();
        m_rtspThread->exit();
    }
}

void QDaulLightCamera::connections()
{
    connect(m_rtspThread,       &Rtsp::sigYuv,              m_glWidget,     &MyGLWidget::showYuv);
    connect(m_pbMainStream,     &QPushButton::clicked,      this,           &QDaulLightCamera::slotSetMainStream);
    connect(m_pbSubStream,      &QPushButton::clicked,      this,           &QDaulLightCamera::slotSetSubStream);
    // connect(m_pbStartPlay,      &QPushButton::clicked,      this,           &QDaulLightCamera::slotStartVideoPlayer);
    // connect(m_pbStopPlay,       &QPushButton::clicked,      this,           &QDaulLightCamera::slotStopVideoPlayer);
}

void QDaulLightCamera::slotSetMainStream()
{
    slotStopVideoPlayer();

    m_pbMainStream->setEnabled(false);
    m_pbSubStream->setEnabled(true);

    m_sUrl = "rtsp://admin:admin123@192.168.1.64:554/PSIA/streaming/channels/101";

    slotStartVideoPlayer();
}

void QDaulLightCamera::slotSetSubStream()
{
    slotStopVideoPlayer();

    m_pbMainStream->setEnabled(true);
    m_pbSubStream->setEnabled(false);

    m_sUrl = "rtsp://admin:admin123@192.168.1.64:554/PSIA/streaming/channels/102";

    slotStartVideoPlayer();
}

void QDaulLightCamera::slotStartVideoPlayer()
{
    slotStopVideoPlayer();

    m_rtspThread->setMediaUrl(m_sUrl);
    m_rtspThread->start();
}

void QDaulLightCamera::slotStopVideoPlayer()
{
    if(m_rtspThread)
    {
        m_rtspThread->requestInterruption();
        m_rtspThread->quit();
        m_rtspThread->wait();
        m_glWidget->update();
    }
}
