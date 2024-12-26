#include "inc/rtsp.h"

Rtsp::Rtsp(QObject *parent) : QThread(parent)
{
    m_url = QString("rtsp://127.0.0.1:8557/0");
}

void Rtsp::setMediaUrl(QString url) {
    m_url = url;
    QByteArray arry = m_url.toLocal8Bit();
    const char *tmpChar = arry.constData();
    strcpy(m_mediaUrl, tmpChar);
}

void Rtsp::run() {
//    ffmpeg 4.0 后已废弃
//    av_register_all();

    avformat_network_init();
    AVFormatContext *pAVFomatContext = avformat_alloc_context();
    AVCodecContext *pAVCodecContext = nullptr;
    AVFrame *pAVFrame = av_frame_alloc();
    AVFrame *pAVFrameYUV = av_frame_alloc();

    AVDictionary *options = NULL;
    av_dict_set(&options, "fflags", "nobuffer", 0);
    av_dict_set(&options, "rtsp_transport", "tcp", 0); // 可选，设置RTSP传输协议为TCP，可能减少网络延时
    av_dict_set(&options, "stimeout", "5000000", 0); // 设置超时时间为5秒（5000000微秒）

    char error_buf[AV_ERROR_MAX_STRING_SIZE];

    int result = avformat_open_input(&pAVFomatContext, /*"rtsp://192.168.1.216:8557/0"*/m_mediaUrl, nullptr, &options);
    if (result < 0)
    {
        qDebug() << QStringLiteral("打开视频失败: ") << result;
        av_strerror(result, error_buf, AV_ERROR_MAX_STRING_SIZE);
        qDebug() << QString::fromLocal8Bit(error_buf, AV_ERROR_MAX_STRING_SIZE);
        return;
    }
    av_dict_free(&options);

    result = avformat_find_stream_info(pAVFomatContext, nullptr);
    if (result < 0)
    {
        qDebug() << QStringLiteral("获取视频流信息失败");
        return;
    }

    int videoStreamIndex = -1;
    for (uint i = 0; i < pAVFomatContext->nb_streams; i++)
    {
        if (pAVFomatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO)
        {
            videoStreamIndex = i;
            break;
        }
    }

    if (videoStreamIndex == -1)
    {
        qDebug() << QStringLiteral("获取视频流索引失败");
        return;
    }

    // 创建AVCodecContext并根据codecpar填充
    pAVCodecContext = avcodec_alloc_context3(nullptr);
    if (!pAVCodecContext) {
        qDebug() << QStringLiteral("无法分配AVCodecContext");
        return;
    }
    if (avcodec_parameters_to_context(pAVCodecContext, pAVFomatContext->streams[videoStreamIndex]->codecpar) < 0) {
        qDebug() << QStringLiteral("无法复制codec parameters到AVCodecContext");
        return;
    }

    int videoWidth = pAVCodecContext->width;
    int videoHeight = pAVCodecContext->height;

    const AVCodec *pAVCodec;

    pAVCodec = avcodec_find_decoder(pAVCodecContext->codec_id);
    SwsContext *pSwsContext = sws_getContext(videoWidth, videoHeight, pAVCodecContext->pix_fmt, videoWidth, videoHeight, AV_PIX_FMT_YUV420P, SWS_BICUBIC, nullptr, nullptr, nullptr);

//    int numBytes = avpicture_get_size(AV_PIX_FMT_YUV420P, videoWidth, videoHeight);
    int numBytes = av_image_get_buffer_size(AV_PIX_FMT_YUV420P, videoWidth, videoHeight, 1);
    uint8_t *out_buffer = (uint8_t *)av_malloc(numBytes * sizeof(uint8_t));

//    avpicture_fill((AVPicture *)pAVFrameYUV, out_buffer, AV_PIX_FMT_YUV420P, videoWidth, videoHeight);
    uint8_t *data[AV_NUM_DATA_POINTERS] = {0};
    int linesize[AV_NUM_DATA_POINTERS] = {0};
    av_image_fill_arrays(data, linesize, out_buffer, AV_PIX_FMT_YUV420P, videoWidth, videoHeight, 1);
    memcpy(pAVFrameYUV->data, data, sizeof(data));
    memcpy(pAVFrameYUV->linesize, linesize, sizeof(linesize));

    int y_size = pAVCodecContext->width * pAVCodecContext->height;
    AVPacket *pAVPacket = (AVPacket *)malloc(sizeof(AVPacket));
    av_new_packet(pAVPacket, y_size);
    av_dump_format(pAVFomatContext, 0, /*"rtsp://192.168.1.216:8557/0"*/m_mediaUrl, 0);
    result = avcodec_open2(pAVCodecContext, pAVCodec, nullptr);
    if (result < 0)
    {
        qDebug() << QStringLiteral("打开解码器失败");
        return;
    }

    qDebug() << QStringLiteral("视频流初始化成功");
    int got_picture = 0;
    while (!isInterruptionRequested())
    {
        int readRes = av_read_frame(pAVFomatContext, pAVPacket);
        if (readRes < 0)
        {
            char read_err[AV_ERROR_MAX_STRING_SIZE];
            av_strerror(readRes, read_err, AV_ERROR_MAX_STRING_SIZE);
            qDebug() << "av_read_frame ERROR: " << QString::fromLocal8Bit(read_err, AV_ERROR_MAX_STRING_SIZE);
            break;
        }

        // 使用新的API进行解码
        if (avcodec_send_packet(pAVCodecContext, pAVPacket) != 0) {
            qDebug() << QStringLiteral("Error sending a packet for decoding");
            av_packet_unref(pAVPacket); // 如果发送失败，记得释放AVPacket
            continue;
        }

        while (avcodec_receive_frame(pAVCodecContext, pAVFrame) == 0)
        {
            got_picture = 1;
            sws_scale(pSwsContext, (const uint8_t *const *)pAVFrame->data, pAVFrame->linesize, 0, videoHeight, pAVFrameYUV->data, pAVFrameYUV->linesize);
            emit sigYuv((uchar *)out_buffer, videoWidth, videoHeight);

            // 假设每次循环只处理一帧，这里可以添加break，或者根据实际情况处理连续帧
            break;
        }

        av_packet_unref(pAVPacket); // 用av_packet_unref替代av_free_packet
    }
    avcodec_close(pAVCodecContext);
    avformat_close_input(&pAVFomatContext);
}
