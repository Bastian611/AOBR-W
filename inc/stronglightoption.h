#ifndef STRONGLIGHTOPTION_H
#define STRONGLIGHTOPTION_H

#include <QWidget>
#include <QDebug>
#include <QTcpSocket>
#include <QMessageBox>
#include <inc/JsonData.h>
#define DEVICE_NAME_STRONGLIGHT 0x04
namespace Ui {
class StrongLightOption;
}

// 强光选项类
class StrongLightOption : public QWidget
{
    Q_OBJECT

public:
    explicit StrongLightOption(QWidget *parent = nullptr);
    ~StrongLightOption();

private:
    Ui::StrongLightOption *ui;
    int g_StrongLightState;
    JsonData *jsondata;
private slots:
    void handle_ConnectState(int deviceName,QString IP,QString Port,int State);
    void on_btn_tcpconnect_device_3_clicked();
    void on_btn_tcpsave_device_3_1_clicked();
signals:
    void sig_TcpConnect();

};

#endif // STRONGLIGHTOPTION_H
