#ifndef GIMBAL_H
#define GIMBAL_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>
#include <inc/JsonData.h>
#define COMMAND_GIMBAL_TURN_STOP 				0X01
#define COMMAND_GIMBAL_TURN_UP 					0X02
#define COMMAND_GIMBAL_TURN_DOWN 				0X03
#define COMMAND_GIMBAL_TURN_LEFT 				0X04
#define COMMAND_GIMBAL_TURN_RIGHT 				0X05
#define COMMAND_GIMBAL_ANGILE_SEARCH_H 			0X06
#define COMMAND_GIMBAL_ANGILE_SEARCH_V 			0X07
#define COMMAND_GIMBAL_ONECLICKZEROING          0X08
#define COMMAND_GIMBAL_REALTIMEACKHAUL_BEFORE_SET 	0X09
#define COMMAND_GIMBAL_REALTIMEACKHAUL_OPEN 	    0X0A
#define COMMAND_GIMBAL_REALTIMEACKHAUL_CLOSE 	    0X0B
#define COMMAND_GIMBAL_REALTIMEACKHAUL_SET 	        0X0C
#define PRESS_STATE_NULL 0
#define PRESS_STATE_PRESSED 1
#define PRESS_STATE_RELEASED 2
#define PRESS_STATE_MAX 3
#define MESSAGE_GIMBAL_ANGLE_H  0X00
#define MESSAGE_GIMBAL_ANGLE_V  0X01

#define SOCKET_GIMBAL_BUFF_SIZE 7
#define DEVICE_NAME_GIMBAL 0X01

// 云台类
class Gimbal:public QObject
{
    Q_OBJECT
public:
    explicit Gimbal(QObject *parent = nullptr);

public slots:
    void start();
    void Init();
    float getAngleHorizontal();
    float getAngleVertical();
private slots:
    void readData();
    void connectedSlot();
    void sendDataSlot(int value,int state);
    void VspeedSliderValueChanged(int value);
    void HspeedSliderValueChanged(int value);
    void btnRealtimeAckhaulOpenClicked();
    void btnRealtimeAckhaulCloseClicked();
    void comboBox_RealtimeAckhaulChange(const QString &arg1);
    void handleDisconnected();
    void handleError(QAbstractSocket::SocketError);
    void btnConnectClicked();
    void btnOneClickZeroingClicked();
    void handle_checkBoxRealtimeAckhaulOpenSet(bool);

private:
    QTcpSocket *tcpSocket;
    JsonData *jsondata;
    quint8 gimbalCommand[13][7];
    QTimer* m_1s;
    const unsigned char speedarray[9]={0X00,0X00,0X07,0X0F,0X1F,0X27,0X2F,0X37,0X3F};
    float angle_horizontal;
    float angle_vertical;
    unsigned char speed_vertical;/*value:0~63*/
    unsigned char speed_horizontal;
    void DataPackage(unsigned char *data,int bytes,long type);
    void chartouchar8(const char *src,unsigned char *dst,unsigned char srclen,unsigned char dstlen);

    void setAngleHorizontal(int);
    void setAngleVertical(int);
    quint8 getSpeedHorizontal();
    quint8 getSpeedVertical();
    void setSpeedHorizontal(quint8);
    void setSpeedVertical(quint8);

    QString ipv4;
    quint16 port;
    void IPInit();
    void DataInit();
signals:
    void startSignal();
    void sendAngleData(int type,int angle);
    void sendDataSignal(int value,int state);
    void sig_ConnectState(int deviceName,QString IP,QString Port,int SocketState);
};

#endif // GIMBAL_H
