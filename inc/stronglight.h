#ifndef STRONGLIGHT_H
#define STRONGLIGHT_H

#include <QObject>
#include <QTcpSocket>
#include "inc/jsondata.h"
#define STRONGLIGHT_IP "192.168.1.71"
#define STRONGLIGHT_PORT 23
#define DEVICE_NAME_STRONGLIGHT 0x04

// 强光类
class StrongLight:public QObject
{
    Q_OBJECT
public:
    explicit StrongLight(QObject *parent = nullptr);
public slots:
    void start();
    void Init();
private slots:
    void readData();
    void connectedSlot();
    void handleDisconnected();
    void handleError(QAbstractSocket::SocketError);
    void btnSwitchOnOff();
    void btnFlashOnOff();
    void btnAngleMin();
    void btnAngleMax();
    void btnConnectClicked();
private:
    QTcpSocket *tcpSocket;
    JsonData *jsondata;
    QString ThreadName;
    QString ipv4;
    quint16 port;
    void IPInit();

signals:
    void startSignal();
    void sig_ConnectState(int deviceName,QString IP,QString Port,int SocketState);
};

#endif // STRONGLIGHT_H
