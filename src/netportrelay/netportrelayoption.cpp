#include "inc/netportrelayoption.h"
#include "ui_netportrelayoption.h"

NetportrelayOption::NetportrelayOption(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NetportrelayOption)
{
    ui->setupUi(this);
    g_NetportrelayState = 0;
    setWindowTitle("网口继电器设置");
    ui->lineEdit_tcpip_device_4->setReadOnly(true);
    ui->lineEdit_tcpport_device_4->setReadOnly(true);
    jsondata = new JsonData();
}

NetportrelayOption::~NetportrelayOption()
{
    delete ui;
}
void NetportrelayOption::handle_ConnectState(int deviceName,QString IP,QString Port,int State)
{
    switch (deviceName) {
    case DEVICE_NAME_NETPORTRELAY:
    {
        qDebug()<<"ip:"<<IP<<"port:"<<Port;
        g_NetportrelayState = State;
        switch (State) {
        case QAbstractSocket::UnconnectedState:
            ui->btn_tcpconnect_device_4->setText("连接");
            break;
        case QAbstractSocket::ConnectedState:
            ui->btn_tcpconnect_device_4->setText("断开");
            ui->lineEdit_tcpip_device_4->setText(IP);
            ui->lineEdit_tcpport_device_4->setText(Port);
            break;
        case QAbstractSocket::ConnectingState:
            ui->lineEdit_tcpip_device_4->setText(IP);
            ui->lineEdit_tcpport_device_4->setText(Port);
            break;
        case QAbstractSocket::ClosingState:
            ui->btn_tcpconnect_device_4->setText("连接");
            qDebug()<<IP<<"disconnect";
            break;
        default:
            break;
        }
    }
    break;
    }
}

void NetportrelayOption::on_btn_tcpconnect_device_4_clicked()
{
    emit sig_TcpConnect();
}


void NetportrelayOption::on_btn_tcpsave_device_4_1_clicked()
{
    QString ipv4;
    quint16 port;
    QMessageBox mgsBox;
    ipv4 = ui->lineEdit_tcpip_device_4_1->text();
    port = ui->lineEdit_tcpport_device_4_1->text().toUShort();
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
    jsondata->ObjectInsertSubObject(&tempjsonobject,"Netportrelay",&tempsubjsonobject);
    jsondata->ObjectWriteToFile(&tempjsonobject,"./IP.json");
    mgsBox.setWindowTitle("IP设置");
    mgsBox.setText("修改成功");
    mgsBox.exec();
}

