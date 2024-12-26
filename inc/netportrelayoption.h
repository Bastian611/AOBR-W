#ifndef NETPORTRELAYOPTION_H
#define NETPORTRELAYOPTION_H

#include <QWidget>
#include <QTcpSocket>
#include <QMessageBox>
#include <inc/JsonData.h>
#define DEVICE_NAME_NETPORTRELAY 0x05
namespace Ui {
class NetportrelayOption;
}

class NetportrelayOption : public QWidget
{
    Q_OBJECT

public:
    explicit NetportrelayOption(QWidget *parent = nullptr);
    ~NetportrelayOption();

private:
    Ui::NetportrelayOption *ui;
    int g_NetportrelayState;
    JsonData *jsondata;
private slots:
    void handle_ConnectState(int deviceName,QString IP,QString Port,int State);
    void on_btn_tcpconnect_device_4_clicked();
    void on_btn_tcpsave_device_4_1_clicked();
signals:
    void sig_TcpConnect();
};

#endif // NETPORTRELAYOPTION_H
