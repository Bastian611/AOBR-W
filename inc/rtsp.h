#ifndef RTSP_H
#define RTSP_H

#include <QObject>
#include <QThread>
#include <QByteArray>
#include <string.h>
#include <QString>
#include <QDebug>

#define MAX_MEDIAURL_LENG 256

extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libavutil/imgutils.h"
#include "libavutil/mathematics.h"
#include "libavutil/samplefmt.h"
#include "libavutil/timestamp.h"
#include "libswscale/swscale.h"
}

class Rtsp : public QThread
{
    Q_OBJECT
public:
    explicit Rtsp(QObject *parent = nullptr);
    void setMediaUrl(QString url);

protected:
    void run() override;

signals:
    void sigYuv(uchar *buf, uint width, uint height);

private:
    QString m_url;
    char m_mediaUrl[MAX_MEDIAURL_LENG] = {0};
};

#endif // RTSP_H
