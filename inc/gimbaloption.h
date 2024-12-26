#ifndef GIMBALOPTION_H
#define GIMBALOPTION_H

#include <QWidget>
#include <QTcpSocket>
#include <inc/JsonData.h>
#include <QMessageBox>
namespace Ui {
class GimbalOption;
}

// 云台选项类
class GimbalOption : public QWidget
{
    Q_OBJECT

public:
    explicit GimbalOption(QWidget *parent = nullptr);
    ~GimbalOption();

private:
    Ui::GimbalOption *ui;
    int g_GimbalState;
    JsonData *jsondata;
private slots:
    void handle_ConnectState(int deviceName,QString IP,QString Port,int State);
    void on_btn_tcpconnect_device_1_clicked();
    void on_btn_tcpsave_device_1_1_clicked();

    void on_btnRealtimeAckhaulOpen_clicked();

    void on_btnRealtimeAckhaulClose_clicked();

    void on_comboBox_RealtimeAckhaul_currentTextChanged(const QString &arg1);

    void on_checkBoxRealtimeAckhaulOpenSet_stateChanged(int arg1);
    void VspinboxSetValue(int);
    void HspinboxSetValue(int);

    void on_spinBox_speed_horizontal_valueChanged(int arg1);

    void on_spinBox_speed_vertical_valueChanged(int arg1);



    void on_btnOneClickZeroing_clicked();

signals:
    void sig_TcpConnect();
    void sig_btnRealtimeAckhaulOpen();
    void sig_btnRealtimeAckhaulClose();
    void sig_RealtimeAckhaulTextChanged(const QString &arg1);
    void sig_checkBoxRealtimeAckhaulOpenSet(bool);
    void sig_Vslidervaluechanged(int);
    void sig_Hslidervaluechanged(int);
    void sig_btnOneClickZeroing();

};

#endif // GIMBALOPTION_H
