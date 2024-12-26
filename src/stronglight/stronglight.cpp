#include "inc/stronglight.h"

StrongLight::StrongLight(QObject *parent) : QObject(parent)
{
    qDebug() << "StrongLight init.";
    /*****/
    jsondata = new JsonData();
    start();
}
void StrongLight::start()
{

    connect(this,&StrongLight::startSignal,this,&StrongLight::Init);
    qDebug() << "StrongLight start";
}
void StrongLight::Init()
{
    ThreadName = this->objectName();
    qDebug()<< ThreadName;
    IPInit();
    qDebug()<<ipv4<<port;
    tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost(ipv4,port);
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(connectedSlot()));
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(handleDisconnected()));
    connect(tcpSocket,SIGNAL(errorOccurred(QAbstractSocket::SocketError)),
            this,SLOT(handleError(QAbstractSocket::SocketError)));
}
void StrongLight::connectedSlot()
{
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readData()));
    if(operator==(ThreadName,"StrongLight"))
    {
        emit sig_ConnectState(DEVICE_NAME_STRONGLIGHT,ipv4,QString("%1").arg(port),QAbstractSocket::ConnectedState);
    }
    else
    {}
    qDebug() << "StrongLight连接成功";
}
//正常操作断开连接
void StrongLight::handleDisconnected()
{
    qDebug() << "StrongLight断开连接";
    disconnect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readData()));
    disconnect(tcpSocket,SIGNAL(connected()),this,SLOT(connectedSlot()));
}
//异常产生断开连接
void StrongLight::handleError(QAbstractSocket::SocketError ErrorNumber)
{
    qDebug() << "发生错误，断开连接"<<ErrorNumber;
    disconnect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readData()));
    disconnect(tcpSocket,SIGNAL(connected()),this,SLOT(connectedSlot()));
    tcpSocket->close();
    /**/
    if(operator==(ThreadName,"StrongLight"))
    {
        emit sig_ConnectState(DEVICE_NAME_STRONGLIGHT,ipv4,QString("%1").arg(port),QAbstractSocket::ClosingState);
    }
    else
    {}

}
void StrongLight::readData()
{
    QByteArray array;
    array = tcpSocket->readAll();
    qDebug() << array.toHex().data();
    //剔除自定义末尾标识符
}
void StrongLight::IPInit()
{
    ipv4 = "";
    port = 0;
    QJsonObject tempjsonobject,tempsubjsonobject;
    QFile file("./IP.json");
    if(file.exists())
    {
        jsondata->ObjectReadFromFile(&tempjsonobject,"./IP.json");

        tempsubjsonobject = jsondata->getSubObject(&tempjsonobject,"StrongLight");
        ipv4 = jsondata->GetObjectValueQString(&tempsubjsonobject,"ip");
        port = jsondata->GetObjectValueQString(&tempsubjsonobject,"port").toUShort();
        if(ipv4.isEmpty())
        {
            tempsubjsonobject = QJsonObject();
            ipv4 = STRONGLIGHT_IP;
            port = STRONGLIGHT_PORT;
            jsondata->ObjectInsertData(&tempsubjsonobject,"ip",ipv4);
            jsondata->ObjectInsertData(&tempsubjsonobject,"port",QString("%1").arg(port));
            jsondata->ObjectInsertSubObject(&tempjsonobject,"StrongLight",&tempsubjsonobject);
            jsondata->ObjectWriteToFile(&tempjsonobject,"./IP.json");
        }
        emit sig_ConnectState(DEVICE_NAME_STRONGLIGHT,ipv4,QString("%1").arg(port),QAbstractSocket::UnconnectedState);
    }
    else
    {
        ipv4 = STRONGLIGHT_IP;
        port = STRONGLIGHT_PORT;
        jsondata->ObjectInsertData(&tempsubjsonobject,"ip",ipv4);
        jsondata->ObjectInsertData(&tempsubjsonobject,"port",QString("%1").arg(port));
        jsondata->ObjectInsertSubObject(&tempjsonobject,"StrongLight",&tempsubjsonobject);
        jsondata->ObjectWriteToFile(&tempjsonobject,"./IP.json");
        emit sig_ConnectState(DEVICE_NAME_STRONGLIGHT,ipv4,QString("%1").arg(port),QAbstractSocket::UnconnectedState);
    }
}
void StrongLight::btnConnectClicked()
{
    if(tcpSocket->state() == QAbstractSocket::UnconnectedState)
    {
        //未连接时
        //从文件中读取ip地址
        QJsonObject tempjsonobject,tempsubjsonobject;
        QFile file("./IP.json");
        if(file.exists())
        {
            jsondata->ObjectReadFromFile(&tempjsonobject,"./IP.json");
            tempsubjsonobject = jsondata->getSubObject(&tempjsonobject,"StrongLight");
            ipv4 = jsondata->GetObjectValueQString(&tempsubjsonobject,"ip");
            port = jsondata->GetObjectValueQString(&tempsubjsonobject,"port").toUShort();
            tcpSocket->connectToHost(ipv4,port);
            connect(tcpSocket,SIGNAL(connected()),this,SLOT(connectedSlot()));
            emit sig_ConnectState(DEVICE_NAME_STRONGLIGHT,ipv4,QString("%1").arg(port),QAbstractSocket::ConnectingState);
        }
        else
        {
            qDebug()<< "IP.json file don't exist.";
        }
        return ;
    }
    else if(tcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        //已连接时
        emit sig_ConnectState(DEVICE_NAME_STRONGLIGHT,ipv4,QString("%1").arg(port),QAbstractSocket::UnconnectedState);
        tcpSocket->close();
    }
}

void StrongLight::btnSwitchOnOff()
{
    static bool flagOnOff = true;
    if(tcpSocket->isWritable())
    {
        if(flagOnOff)
        {
            flagOnOff = !flagOnOff;
            unsigned char data[] = {0xFF,0x01,0x00,0x1F,0x00,0x00,0x20};//绿光照明开启
            tcpSocket->write((char *)data,7);
        }
        else
        {
            flagOnOff = !flagOnOff;
            unsigned char data2[] = {0xFF,0x01,0x00,0x2F,0x00,0x00,0x30};//绿光照明关闭
            tcpSocket->write((char *)data2,7);
        }
    }
}
void StrongLight::btnFlashOnOff()
{
    static bool flagFlashOnOff = true;
    if(tcpSocket->isWritable())
    {
        if(flagFlashOnOff)
        {
            flagFlashOnOff = !flagFlashOnOff;
            unsigned char data[] = {0xFF,0x01,0x00,0x3F,0x00,0x00,0x40};//绿光闪烁开启
            tcpSocket->write((char *)data,7);
        }
        else
        {
            flagFlashOnOff = !flagFlashOnOff;
            unsigned char data2[] = {0xFF,0x01,0x00,0x4F,0x00,0x00,0x50};//绿光闪烁关闭
            tcpSocket->write((char *)data2,7);
        }
    }
}

void StrongLight::btnAngleMin()
{
    unsigned char data[] = {0xFF,0x01,0x00,0x5F,0x03,0xE8,0x4B};//绿光最小发散角
    quint16 checksum = 0x0000;
    checksum = data[1]+data[2]+data[3]+data[4]+data[5];
    data[6] = checksum & 0x00FF;
    if(tcpSocket->isWritable())
    {
        tcpSocket->write((char *)data,7);
    }
}
void StrongLight::btnAngleMax()
{
    unsigned char data[] = {0xFF,0x01,0x00,0x5F,0x00,0x00,0x60};//绿光最大发散角
    if(tcpSocket->isWritable())
    {
        tcpSocket->write((char *)data,7);
    }
}


