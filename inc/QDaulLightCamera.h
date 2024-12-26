#ifndef QDAULLIGHTCAMERA_H
#define QDAULLIGHTCAMERA_H

#include <QWidget>
#include <QObject>
#include <QTcpSocket>
#include <QMediaPlayer>
#include <QVideoFrame>
#include <QMediaPlaylist>
#include <QtMultimediaWidgets>

#include "myglwidget.h"
#include "rtsp.h"
#include "jsondata.h"

namespace Ui {
class QDaulLightCamera;
}

class QDaulLightCamera : public QWidget
{
    Q_OBJECT

public:
    explicit QDaulLightCamera(QWidget *parent = nullptr);
    ~QDaulLightCamera();

    // 创建及销毁句柄
    void createContext();
    void destroyContext();

    void Init();
    void connections();

public slots:
    // 开始播放
    void slotStartVideoPlayer();
    // 停止播放
    void slotStopVideoPlayer();
    // 切换到主码流
    void slotSetMainStream();
    // 切换到子码流
    void slotSetSubStream();

private:
    Ui::QDaulLightCamera    *ui;
    MyGLWidget              *m_glWidget;
    Rtsp                    *m_rtspThread;
    QPushButton             *m_pbMainStream;
    QPushButton             *m_pbSubStream;
    QPushButton             *m_pbStartPlay;
    QPushButton             *m_pbStopPlay;

    // URL地址
    QString     m_sUrl;
};

#endif // QDAULLIGHTCAMERA_H
