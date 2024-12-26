#include "inc/netportrelay.h"

Netportrelay::Netportrelay(QObject *parent) : QObject(parent)
{
    qDebug() << "Netportrelay init.";
    /*****/
    jsondata = new JsonData();
    start();
    dataInit();
}
void Netportrelay::start()
{

    connect(this,&Netportrelay::startSignal,this,&Netportrelay::Init);
    qDebug() << "Netportrelay start";
}
void Netportrelay::Init()
{
    ThreadName = this->objectName();
    qDebug()<< ThreadName;
    IPInit();
    //jsondata = new JsonData();
    tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost(NETPORTRELAY_IP,NETPORTRELAY_PORT);
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(connectedSlot()));
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(handleDisconnected()));
    connect(tcpSocket,SIGNAL(errorOccurred(QAbstractSocket::SocketError)),
            this,SLOT(handleError(QAbstractSocket::SocketError)));
}
void Netportrelay::connectedSlot()
{
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readData()));

    if(operator==(ThreadName,"Netportrelay"))
    {
        emit sig_ConnectState(DEVICE_NAME_NETPORTRELAY,ipv4,QString("%1").arg(port),QAbstractSocket::ConnectedState);
    }
    else
    {}
    qDebug() << "连接成功";
    //启动常连接定时器
    //timer->start();
/**/
    //qDebug() << "连接成功";
}
//正常操作断开连接
void Netportrelay::handleDisconnected()
{
    qDebug() << "Netportrelay断开连接";
    disconnect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readData()));
    disconnect(tcpSocket,SIGNAL(connected()),this,SLOT(connectedSlot()));
}
//异常产生断开连接
void Netportrelay::handleError(QAbstractSocket::SocketError ErrorNumber)
{
    qDebug() << "发生错误，Netportrelay断开连接"<<ErrorNumber;
    disconnect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readData()));
    disconnect(tcpSocket,SIGNAL(connected()),this,SLOT(connectedSlot()));
    tcpSocket->close();

    if(operator==(ThreadName,"Netportrelay"))
    {
        emit sig_ConnectState(DEVICE_NAME_NETPORTRELAY,ipv4,QString("%1").arg(port),QAbstractSocket::ClosingState);
    }
    else
    {}
    /**/
}
void Netportrelay::readData()
{
    QByteArray array;
    qDebug() << "收到read";
    array = tcpSocket->readAll();
    //array = jsondata->ByteArrayTrimmed(array);
    qDebug() << array.toHex().data();
    //剔除自定义末尾标识符
    //JsonParsing(array);
}
void Netportrelay::sendData()
{
    unsigned char data[] = {0x00,0x00,0x00,0x00,0x00,0x06,0x11,0x10,0x05,0x00,0xFF,0xFF};//开启D0第一路主动上报，触发D0主动上报方式:D0状态发生变化则上报
    //unsigned char data2[] = {0x11,0x01,0x00,0x00,0x00,0x04,0x3F,0x59};
    tcpSocket->write((char *)data,12);
    //tcpSocket->write((char *)data2,8);
    qDebug()<<"四路输出继电器状态";
}
void Netportrelay::IPInit()
{
    ipv4 = "";
    port = 0;
    //jsondata = new JsonData();
    QJsonObject tempjsonobject,tempsubjsonobject;
    QFile file("./IP.json");
    if(file.exists())
    {
        jsondata->ObjectReadFromFile(&tempjsonobject,"./IP.json");

        tempsubjsonobject = jsondata->getSubObject(&tempjsonobject,"Netportrelay");
        ipv4 = jsondata->GetObjectValueQString(&tempsubjsonobject,"ip");
        port = jsondata->GetObjectValueQString(&tempsubjsonobject,"port").toUShort();
        if(ipv4.isEmpty())
        {
            tempsubjsonobject = QJsonObject();
            ipv4 = "192.168.1.10";
            port = 10123;
            jsondata->ObjectInsertData(&tempsubjsonobject,"ip",ipv4);
            jsondata->ObjectInsertData(&tempsubjsonobject,"port",QString("%1").arg(port));
            jsondata->ObjectInsertSubObject(&tempjsonobject,"Netportrelay",&tempsubjsonobject);
            jsondata->ObjectWriteToFile(&tempjsonobject,"./IP.json");
        }
        emit sig_ConnectState(DEVICE_NAME_NETPORTRELAY,ipv4,QString("%1").arg(port),QAbstractSocket::UnconnectedState);
    }
    else
    {
        ipv4 = "192.168.1.10";
        port = 10123;
        jsondata->ObjectInsertData(&tempsubjsonobject,"ip",ipv4);
        jsondata->ObjectInsertData(&tempsubjsonobject,"port",QString("%1").arg(port));
        jsondata->ObjectInsertSubObject(&tempjsonobject,"Netportrelay",&tempsubjsonobject);
        jsondata->ObjectWriteToFile(&tempjsonobject,"./IP.json");
        emit sig_ConnectState(DEVICE_NAME_NETPORTRELAY,ipv4,QString("%1").arg(port),QAbstractSocket::UnconnectedState);
    }
}
void Netportrelay::btnConnectClicked()
{
    if(tcpSocket->state() == QAbstractSocket::UnconnectedState)
    {
        //未连接时
        //qDebug() << "UnconnectedState";
        //从文件中读取ip地址
        QJsonObject tempjsonobject,tempsubjsonobject;
        QFile file("./IP.json");
        if(file.exists())
        {
            jsondata->ObjectReadFromFile(&tempjsonobject,"./IP.json");
            tempsubjsonobject = jsondata->getSubObject(&tempjsonobject,"Netportrelay");
            ipv4 = jsondata->GetObjectValueQString(&tempsubjsonobject,"ip");
            port = jsondata->GetObjectValueQString(&tempsubjsonobject,"port").toUShort();
            tcpSocket->connectToHost(ipv4,port);
            connect(tcpSocket,SIGNAL(connected()),this,SLOT(connectedSlot()));
            emit sig_ConnectState(DEVICE_NAME_NETPORTRELAY,ipv4,QString("%1").arg(port),QAbstractSocket::ConnectingState);
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
        //qDebug() << "ConnectedState";
        emit sig_ConnectState(DEVICE_NAME_NETPORTRELAY,ipv4,QString("%1").arg(port),QAbstractSocket::UnconnectedState);
        tcpSocket->close();
    }
}
void Netportrelay::dataInit()
{
    unsigned char Command[8][12] =  {
    {0x00,0x00,0x00,0x00,0x00,0x06,0x11,0x05,0x00,0x00,0x00,0x00},//DO1打开
    {0x00,0x00,0x00,0x00,0x00,0x06,0x11,0x05,0x00,0x00,0xFF,0x00},//DO1闭合
    {0x00,0x00,0x00,0x00,0x00,0x06,0x11,0x05,0x00,0x01,0x00,0x00},//DO2打开
    {0x00,0x00,0x00,0x00,0x00,0x06,0x11,0x05,0x00,0x01,0xFF,0x00},//DO2闭合
    {0x00,0x00,0x00,0x00,0x00,0x06,0x11,0x05,0x00,0x02,0x00,0x00},//DO3打开
    {0x00,0x00,0x00,0x00,0x00,0x06,0x11,0x05,0x00,0x02,0xFF,0x00},//DO3闭合
    {0x00,0x00,0x00,0x00,0x00,0x06,0x11,0x05,0x00,0x03,0x00,0x00},//DO4打开
    {0x00,0x00,0x00,0x00,0x00,0x06,0x11,0x05,0x00,0x03,0xFF,0x00} //DO4闭合
    };
    memset(switchCommand,0,sizeof(switchCommand));
    memcpy(switchCommand,Command,sizeof(Command));

}
void Netportrelay::btnSwitch_1()
{
    static bool flag1 = true;
    if(tcpSocket->isWritable())
    {
        if(flag1)
        {
            flag1 = !flag1;
            tcpSocket->write((char *)switchCommand[NETPORTRELAY_SWITCH_CLOSE_DO_1],NETPORTRELAY_SWITCH_COMMAND_LENGTH);
        }
        else
        {
            flag1 = !flag1;
            tcpSocket->write((char *)switchCommand[NETPORTRELAY_SWITCH_OPEN_DO_1],NETPORTRELAY_SWITCH_COMMAND_LENGTH);
        }
    }
}
void Netportrelay::btnSwitch_2()
{
    static bool flag2 = true;
    if(tcpSocket->isWritable())
    {
        if(flag2)
        {
            flag2 = !flag2;
            tcpSocket->write((char *)switchCommand[NETPORTRELAY_SWITCH_CLOSE_DO_2],NETPORTRELAY_SWITCH_COMMAND_LENGTH);
        }
        else
        {
            flag2 = !flag2;
            tcpSocket->write((char *)switchCommand[NETPORTRELAY_SWITCH_OPEN_DO_2],NETPORTRELAY_SWITCH_COMMAND_LENGTH);
        }
    }
}
void Netportrelay::btnSwitch_3()
{
    static bool flag3 = true;
    if(tcpSocket->isWritable())
    {
        if(flag3)
        {
            flag3 = !flag3;
            tcpSocket->write((char *)switchCommand[NETPORTRELAY_SWITCH_CLOSE_DO_3],NETPORTRELAY_SWITCH_COMMAND_LENGTH);
        }
        else
        {
            flag3 = !flag3;
            tcpSocket->write((char *)switchCommand[NETPORTRELAY_SWITCH_OPEN_DO_3],NETPORTRELAY_SWITCH_COMMAND_LENGTH);
        }
    }
}
void Netportrelay::btnSwitch_4()
{
    static bool flag4 = true;
    if(tcpSocket->isWritable())
    {
        if(flag4)
        {
            flag4 = !flag4;
            tcpSocket->write((char *)switchCommand[NETPORTRELAY_SWITCH_CLOSE_DO_4],NETPORTRELAY_SWITCH_COMMAND_LENGTH);
        }
        else
        {
            flag4 = !flag4;
            tcpSocket->write((char *)switchCommand[NETPORTRELAY_SWITCH_OPEN_DO_4],NETPORTRELAY_SWITCH_COMMAND_LENGTH);
        }
    }
}
