#ifndef FFMPEG_H
#define FFMPEG_H

#include <QObject>

#include "stdio.h"

extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libavformat/avio.h"
#include "libavutil/file.h"
}

struct buffer_data
{
    uint8_t *ptr;
    size_t size;
};

static int read_packet(void *opaque, uint8_t *buf, int buf_size);

class FFmpeg : public QObject
{
    Q_OBJECT
public:
    explicit FFmpeg(QObject *parent = 0);

    int avio_reading();
};

#endif // FFMPEG_H
