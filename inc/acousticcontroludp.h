#ifndef ACOUSTICCONTROLUDP_H
#define ACOUSTICCONTROLUDP_H

#include <QObject>
#include <QUdpSocket>
#include <QAudioInput>
#include <QFile>
#include <QTimer>
#include <inc/jsondata.h>
#define DEVICE_NAME_ACOUSTICCONTROL_UDP 0X02


// UDP声音控制类
class AcousticcontrolUDP:public QObject
{
    Q_OBJECT
public:
    explicit AcousticcontrolUDP(QObject *parent = nullptr);
public slots:
    void start();
    void Init();
private slots:
    void readData();
    void sendData();
    void AudioInStreamReadyRead();
    void AudioInStreamStatus(QAudio::State);
    void stopRecording();
    void btnBroadcastClicked();
    void SliderCapVolumeChanged(int);
    void TimeoutSetIP();
    void handle_IPSet(QString ip,QString port);
private:
    QUdpSocket *udpSocket;
    QFile destinationFile;
    QAudioInput *audioIn;
    QIODevice *audio_InStream;
    QString ipv4;
    quint16 port;
    JsonData *jsondata;
    void audioInTest();
    void audioInInit();
    void IPInit();
signals:
    void startSignal();
    void sig_ConnectState(int deviceName,QString IP,QString Port,int SocketState);
};

#endif // ACOUSTICCONTROLUDP_H
