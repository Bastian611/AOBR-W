#include "inc/acousticcontroloption.h"
#include "ui_acousticcontroloption.h"
#define DEVICE_NAME_ACOUSTICCONTROL_UDP 0X02
#define DEVICE_NAME_ACOUSTICCONTROL 0X03
AcousticcontrolOption::AcousticcontrolOption(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AcousticcontrolOption)
{
    ui->setupUi(this);
    setWindowTitle("强声设置");
    ui->lineEdit_tcpip_device_2->setReadOnly(true);
    ui->lineEdit_tcpport_device_2->setReadOnly(true);
    ui->lineEdit_udpip_device_2->setReadOnly(true);
    ui->lineEdit_udpport_device_2->setReadOnly(true);
    jsondata = new JsonData();
}

AcousticcontrolOption::~AcousticcontrolOption()
{
    delete ui;
}
void AcousticcontrolOption::handle_ConnectState(int deviceName,QString IP,QString Port,int State)
{
    switch (deviceName) {
    break;
    case DEVICE_NAME_ACOUSTICCONTROL_UDP:
    {
        qDebug()<<"UDPip:"<<IP<<"port:"<<Port;
        ui->lineEdit_udpip_device_2->setText(IP);
        ui->lineEdit_udpport_device_2->setText(Port);
        qDebug()<<"AcousticcontrolUDPState:"<<State;
    }
    break;
    case DEVICE_NAME_ACOUSTICCONTROL:
    {
        qDebug()<<"ip:"<<IP<<"port:"<<Port;
        switch (State) {
        case QAbstractSocket::UnconnectedState:
            ui->btn_tcpconnect_device_2->setText("连接");
            break;
        case QAbstractSocket::ConnectedState:
            ui->btn_tcpconnect_device_2->setText("断开");
            ui->lineEdit_tcpip_device_2->setText(IP);
            ui->lineEdit_tcpport_device_2->setText(Port);
            break;
        case QAbstractSocket::ConnectingState:
            ui->lineEdit_tcpip_device_2->setText(IP);
            ui->lineEdit_tcpport_device_2->setText(Port);
            break;
        case QAbstractSocket::ClosingState:
            ui->btn_tcpconnect_device_2->setText("连接");
            qDebug()<<IP<<"disconnect";
            break;
        default:
            break;
        }
        qDebug()<<"AcousticcontrolTCPState:"<<State;
    }
    break;
        break;
    default:
        break;
    }
}
void AcousticcontrolOption::on_btn_tcpconnect_device_2_clicked()
{
    emit sig_btn_tcpconnect();
}
void AcousticcontrolOption::on_btn_tcpsave_device_2_1_clicked()
{
    QString ipv4;
    quint16 port;
    ipv4 = ui->lineEdit_tcpip_device_2_1->text();
    port = ui->lineEdit_tcpport_device_2_1->text().toUShort();
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
    jsondata->ObjectInsertSubObject(&tempjsonobject,"Acousticcontrol",&tempsubjsonobject);
    jsondata->ObjectWriteToFile(&tempjsonobject,"./IP.json");
    QMessageBox mgsBox;
    mgsBox.setWindowTitle("IP设置");
    mgsBox.setText("修改成功");
    mgsBox.exec();
}
void AcousticcontrolOption::on_btn_udpsave_device_2_1_clicked()
{
    QString ipv4;
    quint16 port;
    ipv4 = ui->lineEdit_udpip_device_2_1->text();
    port = ui->lineEdit_udpport_device_2_1->text().toUShort();
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
    jsondata->ObjectInsertSubObject(&tempjsonobject,"AcousticcontrolUDP",&tempsubjsonobject);
    jsondata->ObjectWriteToFile(&tempjsonobject,"./IP.json");
    emit sig_IPSet(ipv4,QString("%1").arg(port));
    QMessageBox mgsBox;
    mgsBox.setWindowTitle("IP设置");
    mgsBox.setText("修改成功");
    mgsBox.exec();
}


void AcousticcontrolOption::on_pushButton_uploadFilePathChoose_clicked()
{
    //获取当前目录
    QString curPath= QDir::currentPath()+ "/" +"../music";
    QString dlgTitle="选择音频文件"; //对话框标题
    QString filter="音频文件(*.mp3 *.wav *.wma);;mp3文件(*.mp3);;wav文件(*.wav);;wma文件(*.wma);;所有文件(*.*)"; //文件过滤器
    QStringList fileList=QFileDialog ::getOpenFileNames(this,dlgTitle,curPath,filter);
    if(fileList.isEmpty())
    {
        return;
    }
    ui->lineEdit_uploadFilePath->setText(fileList.at(0));
    emit sig_getUploadFilePath(fileList.at(0));
}


void AcousticcontrolOption::on_btnUploadFile_clicked()
{
    emit sig_btnUploadFile();
}


void AcousticcontrolOption::on_btnOneKey_clicked()
{
    emit sig_btnOneKey();
}

