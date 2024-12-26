#include "inc/gimbaloption.h"
#include "ui_gimbaloption.h"
#include <QDebug>
#define DEVICE_NAME_GIMBAL 0x01
GimbalOption::GimbalOption(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GimbalOption)
{
    ui->setupUi(this);
    setWindowTitle("云台设置");
    g_GimbalState = 0x00;
    ui->lineEdit_tcpip_device_1->setReadOnly(true);
    ui->lineEdit_tcpport_device_1->setReadOnly(true);
    jsondata = new JsonData();
    QStringList RealtimeAckhaul;//5hz~100hz
    RealtimeAckhaul << "5";
    RealtimeAckhaul << "10";
    RealtimeAckhaul << "15";
    RealtimeAckhaul << "20";
    RealtimeAckhaul << "25";
    ui->comboBox_RealtimeAckhaul->addItems(RealtimeAckhaul);

    ui->spinBox_speed_horizontal->setRange(1,8);
    ui->spinBox_speed_vertical->setRange(1,8);
    ui->spinBox_speed_horizontal->setMaximum(8);
    ui->spinBox_speed_horizontal->setMinimum(1);
    ui->spinBox_speed_vertical->setMaximum(8);
    ui->spinBox_speed_vertical->setMinimum(1);
    ui->spinBox_speed_horizontal->setValue(1);
    ui->spinBox_speed_vertical->setValue(1);
}

GimbalOption::~GimbalOption()
{
    delete ui;
}
void GimbalOption::handle_ConnectState(int deviceName,QString IP,QString Port,int State)
{
    switch (deviceName) {
    case DEVICE_NAME_GIMBAL:
    {
        qDebug()<<"ip:"<<IP<<"port:"<<Port;
        g_GimbalState = State;
        switch (State) {
        case QAbstractSocket::UnconnectedState:
            ui->btn_tcpconnect_device_1->setText("连接");
            break;
        case QAbstractSocket::ConnectedState:
            ui->btn_tcpconnect_device_1->setText("断开");
            ui->lineEdit_tcpip_device_1->setText(IP);
            ui->lineEdit_tcpport_device_1->setText(Port);
            break;
        case QAbstractSocket::ConnectingState:
            ui->lineEdit_tcpip_device_1->setText(IP);
            ui->lineEdit_tcpport_device_1->setText(Port);
            break;
        case QAbstractSocket::ClosingState:
            ui->btn_tcpconnect_device_1->setText("连接");
            qDebug()<<IP<<"disconnect";
            break;
        default:
            break;
        }
    }
    break;
    }
}

void GimbalOption::on_btn_tcpconnect_device_1_clicked()
{
    emit sig_TcpConnect();
}


void GimbalOption::on_btn_tcpsave_device_1_1_clicked()
{
    QString ipv4;
    quint16 port;
    QMessageBox mgsBox;
    ipv4 = ui->lineEdit_tcpip_device_1_1->text();
    port = ui->lineEdit_tcpport_device_1_1->text().toUShort();
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
    jsondata->ObjectInsertSubObject(&tempjsonobject,"Gimbal",&tempsubjsonobject);
    jsondata->ObjectWriteToFile(&tempjsonobject,"./IP.json");
    mgsBox.setWindowTitle("IP设置");
    mgsBox.setText("修改成功");
    mgsBox.exec();

}


void GimbalOption::on_btnRealtimeAckhaulOpen_clicked()
{
    emit sig_btnRealtimeAckhaulOpen();
}


void GimbalOption::on_btnRealtimeAckhaulClose_clicked()
{
    emit sig_btnRealtimeAckhaulClose();
}


void GimbalOption::on_comboBox_RealtimeAckhaul_currentTextChanged(const QString &arg1)
{
    emit sig_RealtimeAckhaulTextChanged(arg1);
}


void GimbalOption::on_checkBoxRealtimeAckhaulOpenSet_stateChanged(int arg1)
{
    Q_UNUSED(arg1)
    if(ui->checkBoxRealtimeAckhaulOpenSet->isChecked())
    {
        emit sig_checkBoxRealtimeAckhaulOpenSet(true);
    }
    else
    {
    }
}
void GimbalOption::VspinboxSetValue(int value)
{
    ui->spinBox_speed_vertical->setValue(value);
}
void GimbalOption::HspinboxSetValue(int value)
{
    ui->spinBox_speed_horizontal->setValue(value);
}

void GimbalOption::on_spinBox_speed_horizontal_valueChanged(int arg1)
{
    emit sig_Hslidervaluechanged(arg1);
}
void GimbalOption::on_spinBox_speed_vertical_valueChanged(int arg1)
{
    emit sig_Vslidervaluechanged(arg1);
}





void GimbalOption::on_btnOneClickZeroing_clicked()
{
    emit sig_btnOneClickZeroing();
}

