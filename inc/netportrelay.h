#ifndef NETPORTRELAY_H
#define NETPORTRELAY_H

#include <QObject>
#include <QTcpSocket>
#include <inc/JsonData.h>
#define NETPORTRELAY_IP "192.168.1.10"
#define NETPORTRELAY_PORT 10123

#define NETPORTRELAY_SWITCH_OPEN_DO_1   0
#define NETPORTRELAY_SWITCH_CLOSE_DO_1  1
#define NETPORTRELAY_SWITCH_OPEN_DO_2   2
#define NETPORTRELAY_SWITCH_CLOSE_DO_2  3
#define NETPORTRELAY_SWITCH_OPEN_DO_3   4
#define NETPORTRELAY_SWITCH_CLOSE_DO_3  5
#define NETPORTRELAY_SWITCH_OPEN_DO_4   6
#define NETPORTRELAY_SWITCH_CLOSE_DO_4  7

#define NETPORTRELAY_SWITCH_COMMAND_LENGTH 12

#define DEVICE_NAME_NETPORTRELAY 0x05
class Netportrelay:public QObject
{
    Q_OBJECT
public:
    explicit Netportrelay(QObject *parent = nullptr);
public slots:
    void start();
    void Init();
private slots:
    void readData();
    void sendData();
    void connectedSlot();
    void handleDisconnected();
    void handleError(QAbstractSocket::SocketError);
    void btnSwitch_1();
    void btnSwitch_2();
    void btnSwitch_3();
    void btnSwitch_4();
    void btnConnectClicked();
private:
    QTcpSocket *tcpSocket;
    JsonData *jsondata;
    QString ThreadName;
    QString ipv4;
    quint16 port;
    void IPInit();
    void dataInit();
    unsigned char switchCommand[8][12];

signals:
    void startSignal();
    void sig_ConnectState(int deviceName,QString IP,QString Port,int SocketState);
};

#endif // NETPORTRELAY_H
