#ifndef ACOUSTICCONTROL_H
#define ACOUSTICCONTROL_H
#pragma once
#include <QObject>
#include <QTcpSocket>
#include <QTimer>
#include "inc/jsondata.h"
#include <QMutex>
#include <QListWidgetItem>
#define DEVICE_NAME_ACOUSTICCONTROL 0X03


#define PALY_MODE_IDLE -1
#define PALY_MODE_PLAYER 0
#define PALY_MODE_ONE_KEY 1
#define PALY_MODE_MIC_BROADCAST 2

// 声音控制类
class Acousticcontrol:public QObject
{
    Q_OBJECT
public:
    explicit Acousticcontrol(QObject *parent = nullptr);
public slots:
    void start();
    void Init();
private slots:
    void readData();
    //void sendData();
    void playerListUpdate();
    void connectedSlot();
    void Play();
    void Pause();
    void SongPrevious();
    void SongNext();
    void onlineTimeout();
    void SongSinglecycle();
    void SliderPLayerVolumeChanged(int);
    void SliderCapVolumeChanged(int);
    void SongListdoubleClick(const QModelIndex &modelIndex);
    void OneKeyClicked();
    void hander_getUploadFilePath(QString);
    void UploadFileClicked();
    void btnConnectClicked();
    void handleDisconnected();
    void handleError(QAbstractSocket::SocketError);
    void btnBroadcastPressed();
private:
    QString ThreadName;
    QTcpSocket *tcpSocket;
    JsonData *jsondata;
    QMutex mutex;
    int g_Cseq;
    int g_Code;
    QString g_CurrentPlayerIndex;
    quint64 g_CurrentPlayerIndex_MAX;
    void CommandJsonFileInit();
    void JsonParsing(QByteArray);
    void SetPlayVolume(int);
    int  GetPlayVolume();
    void SetCollectionVolume(int);
    int  GetCollectionVolume();
    void SetCseq(int);
    void CseqSelfIncrease();
    int  GetCseq();
    void SetCode(int);
    int  GetCode();
    void SetCurrentPlayerIndex(QString);
    QString  GetCurrentPlayerIndex();
    void SetCurrentPlayerIndex_MAX(quint64);
    quint64  GetCurrentPlayerIndex_MAX();

    void handle_load_play_list(QJsonArray *jsonarray);
    QJsonObject g_JsonObject;
    QTimer *timer;
    void onlineTimerInit();
    QString UploadFilePath;
    QFile UploadFile;
    QString ipv4;
    quint16 port;
    void IPInit();
    int CurrentPlayMode;
signals:
    void startSignal();
    void sig_listWidgetClear();
    void sig_listWidgetAddItem(QString);
    void sig_SongPrevious(QString);
    void sig_SongNext(QString);
    void sig_ConnectState(int deviceName,QString IP,QString Port,int SocketState);
};

#endif // ACOUSTICCONTROL_H
