#ifndef ACOUSTICCONTROLOPTION_H
#define ACOUSTICCONTROLOPTION_H

#include <QWidget>
#include <QDebug>
#include <QTcpSocket>
#include <inc/JsonData.h>
#include <QFileDialog>
#include <QMessageBox>
namespace Ui {
class AcousticcontrolOption;
}

// 声音控制选项类
class AcousticcontrolOption : public QWidget
{
    Q_OBJECT

public:
    explicit AcousticcontrolOption(QWidget *parent = nullptr);
    ~AcousticcontrolOption();

private:
    Ui::AcousticcontrolOption *ui;
    JsonData *jsondata;
private slots:
    void handle_ConnectState(int deviceName,QString IP,QString Port,int State);
    void on_btn_tcpconnect_device_2_clicked();
    void on_btn_tcpsave_device_2_1_clicked();

    void on_btn_udpsave_device_2_1_clicked();

    void on_pushButton_uploadFilePathChoose_clicked();

    void on_btnUploadFile_clicked();

    void on_btnOneKey_clicked();

signals:
    void sig_btn_tcpconnect();
    void sig_IPSet(QString ip,QString port);
    void sig_getUploadFilePath(QString);
    void sig_btnUploadFile();
    void sig_btnOneKey();
};

#endif // ACOUSTICCONTROLOPTION_H
