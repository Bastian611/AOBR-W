#include "inc/stronglightoption.h"
#include "ui_stronglightoption.h"

StrongLightOption::StrongLightOption(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StrongLightOption)
{
    ui->setupUi(this);
    g_StrongLightState = 0;
    setWindowTitle("强光设置");
    ui->lineEdit_tcpip_device_3->setReadOnly(true);
    ui->lineEdit_tcpport_device_3->setReadOnly(true);
    jsondata = new JsonData();
}

StrongLightOption::~StrongLightOption()
{
    delete ui;
}
void StrongLightOption::handle_ConnectState(int deviceName,QString IP,QString Port,int State)
{
    switch (deviceName) {
    case DEVICE_NAME_STRONGLIGHT:
    {
        qDebug()<<"ip:"<<IP<<"port:"<<Port;
        g_StrongLightState = State;
        switch (State) {
        case QAbstractSocket::UnconnectedState:
            ui->btn_tcpconnect_device_3->setText("连接");
            break;
        case QAbstractSocket::ConnectedState:
            ui->btn_tcpconnect_device_3->setText("断开");
            ui->lineEdit_tcpip_device_3->setText(IP);
            ui->lineEdit_tcpport_device_3->setText(Port);
            break;
        case QAbstractSocket::ConnectingState:
            ui->lineEdit_tcpip_device_3->setText(IP);
            ui->lineEdit_tcpport_device_3->setText(Port);
            break;
        case QAbstractSocket::ClosingState:
            ui->btn_tcpconnect_device_3->setText("连接");
            qDebug()<<IP<<"disconnect";
            break;
        default:
            break;
        }
    }
    break;
    }
}

void StrongLightOption::on_btn_tcpconnect_device_3_clicked()
{
    emit sig_TcpConnect();
}


void StrongLightOption::on_btn_tcpsave_device_3_1_clicked()
{
    QString ipv4;
    quint16 port;
    QMessageBox mgsBox;
    ipv4 = ui->lineEdit_tcpip_device_3_1->text();
    port = ui->lineEdit_tcpport_device_3_1->text().toUShort();
    QJsonObject tempjsonobject,tempsubjsonobject;
    QFile file("./IP.json");
    if(file.exists())
    {
        jsondata->ObjectReadFromFile(&tempjsonobject,"./IP.json");
    }
    else
    {
    }
    jsondata->ObjectInsertData(&tempsubjsonobject,"ip",ipv4);
    jsondata->ObjectInsertData(&tempsubjsonobject,"port",QString("%1").arg(port));
    jsondata->ObjectInsertSubObject(&tempjsonobject,"StrongLight",&tempsubjsonobject);
    jsondata->ObjectWriteToFile(&tempjsonobject,"./IP.json");
    mgsBox.setWindowTitle("IP设置");
    mgsBox.setText("修改成功");
    mgsBox.exec();
}

