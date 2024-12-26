#include "inc/gimbal.h"
Gimbal::Gimbal(QObject *parent) : QObject(parent)
{
    qDebug() << "Gimbal init.";
    jsondata = new JsonData();
    start();

}
void Gimbal::Init()
{
    qDebug()<< this->objectName();
    tcpSocket = new QTcpSocket(this);
    qDebug()<<"connectToHost:"<<ipv4 << port;

    tcpSocket->connectToHost(ipv4,port);
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(connectedSlot()));
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(handleDisconnected()));
    connect(tcpSocket,SIGNAL(errorOccurred(QAbstractSocket::SocketError)),
            this,SLOT(handleError(QAbstractSocket::SocketError)));
}
void Gimbal::start()
{
    IPInit();
    DataInit();
    m_1s = new QTimer(this);
    m_1s->setInterval(10);
    m_1s->start();
    //jsondata = new JsonData();
    connect(this,&Gimbal::startSignal,this,&Gimbal::Init);
    connect(this,&Gimbal::sendDataSignal,this,&Gimbal::sendDataSlot);
    qDebug() << "Gimbal start";

}
void Gimbal::connectedSlot()
{
    // connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readData()));
    connect(m_1s,       &QTimer::timeout,   this,   &Gimbal::readData);

    emit sig_ConnectState(DEVICE_NAME_GIMBAL,ipv4,QString("%1").arg(port),QAbstractSocket::ConnectedState);

    qDebug() << "Gimbal连接成功";
}
//正常操作断开连接
void Gimbal::handleDisconnected()
{
    qDebug() << "Gimbal断开连接";
    // disconnect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readData()));
    // disconnect(m_1s,    &QTimer::timeout,   this,   &Gimbal::readData);
    m_1s->stop();
    disconnect(tcpSocket,SIGNAL(connected()),this,SLOT(connectedSlot()));
}
//异常产生断开连接
void Gimbal::handleError(QAbstractSocket::SocketError ErrorNumber)
{
    qDebug() << "发生错误，断开连接,请检查客户端和服务端ip和端口"<<ErrorNumber;
    // disconnect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readData()));
    // disconnect(m_1s,    &QTimer::timeout,   this,   &Gimbal::readData);
    disconnect(tcpSocket,SIGNAL(connected()),this,SLOT(connectedSlot()));
    tcpSocket->close();
    // m_1s->stop();
    emit sig_ConnectState(DEVICE_NAME_GIMBAL,ipv4,QString("%1").arg(port),QAbstractSocket::ClosingState);
}
void Gimbal::IPInit()
{
    ipv4 = "";
    port = 0;
    //jsondata = new JsonData();
    QJsonObject tempjsonobject,tempsubjsonobject;
    QFile file("./IP.json");
    if(file.exists())
    {
        jsondata->ObjectReadFromFile(&tempjsonobject,"./IP.json");

        tempsubjsonobject = jsondata->getSubObject(&tempjsonobject,"Gimbal");
        ipv4 = jsondata->GetObjectValueQString(&tempsubjsonobject,"ip");
        port = jsondata->GetObjectValueQString(&tempsubjsonobject,"port").toUShort();
        if(ipv4.isEmpty())
        {
            tempsubjsonobject = QJsonObject();
            ipv4 = "192.168.1.7";
            port = 23;
            jsondata->ObjectInsertData(&tempsubjsonobject,"ip",ipv4);
            jsondata->ObjectInsertData(&tempsubjsonobject,"port",QString("%1").arg(port));
            jsondata->ObjectInsertSubObject(&tempjsonobject,"Gimbal",&tempsubjsonobject);
            jsondata->ObjectWriteToFile(&tempjsonobject,"./IP.json");
        }
        emit sig_ConnectState(DEVICE_NAME_GIMBAL,ipv4,QString("%1").arg(port),QAbstractSocket::UnconnectedState);
    }
    else
    {
        ipv4 = "192.168.1.7";
        port = 23;
        jsondata->ObjectInsertData(&tempsubjsonobject,"ip",ipv4);
        jsondata->ObjectInsertData(&tempsubjsonobject,"port",QString("%1").arg(port));
        jsondata->ObjectInsertSubObject(&tempjsonobject,"Gimbal",&tempsubjsonobject);
        jsondata->ObjectWriteToFile(&tempjsonobject,"./IP.json");
        emit sig_ConnectState(DEVICE_NAME_GIMBAL,ipv4,QString("%1").arg(port),QAbstractSocket::UnconnectedState);
    }
}

void Gimbal::DataInit()
{
    quint8 Command[][7] = {
        {0XFF,0X01,0X00,0X00,0X00,0X00,0X01},//空白填充，占据0下标
        {0XFF,0X01,0X00,0X00,0X00,0X00,0X01},//1全部停止（上下左右操作）
        {0XFF,0X01,0X00,0X08,0X00,0X3F,0X48},//2垂直向上
        {0XFF,0X01,0X00,0X10,0X00,0X3F,0X50},//3垂直向下
        {0XFF,0X01,0X00,0X04,0X3F,0X00,0X44},//4水平向左
        {0XFF,0X01,0X00,0X02,0X3F,0X00,0X42},//5水平向右
        {0XFF,0X01,0X00,0X51,0X00,0X00,0X52},//6水平角度主动查询
        {0XFF,0X01,0X00,0X53,0X00,0X00,0X54},//7垂直角度主动查询
        {0XFF,0X01,0X00,0X07,0X00,0X63,0X6B},//8一键归零
        {0XFF,0X01,0X00,0X95,0X03,0X01,0X9A},//9角度实时回传修改前置指令
        {0XFF,0X01,0X00,0X09,0X00,0X05,0X0F},//10角度实时回传开
        {0XFF,0X01,0X00,0X0B,0X00,0X05,0X11},//11角度实时回传关
        {0XFF,0X01,0X00,0X97,0X00,0XC8,0X60},//12设置角度回传每秒次数 00 01
        //{0XFF,0X01,0X00,0X07,0X00,0X78,0X80},//13远程重启
        //{0XFF,0X01,0X00,0X03,0X00,0X77,0X7B},//14设置119号预置位，上电自检的位置
        //{0XFF,0X01,0X00,0X07,0X00,0X77,0X7F},//15调用119号预置位，自检

    };
    memcpy(gimbalCommand,Command,sizeof Command);
    speed_vertical = 0X3F;/*value:0~63*/
    speed_horizontal = 0X3F;
    angle_horizontal = 0.0;
    angle_vertical = 0.0;
}
void Gimbal::btnConnectClicked()
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
            tempsubjsonobject = jsondata->getSubObject(&tempjsonobject,"Gimbal");
            ipv4 = jsondata->GetObjectValueQString(&tempsubjsonobject,"ip");
            port = jsondata->GetObjectValueQString(&tempsubjsonobject,"port").toUShort();
            tcpSocket->connectToHost(ipv4,port);
            connect(tcpSocket,SIGNAL(connected()),this,SLOT(connectedSlot()));
            emit sig_ConnectState(DEVICE_NAME_GIMBAL,ipv4,QString("%1").arg(port),QAbstractSocket::ConnectingState);
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
        emit sig_ConnectState(DEVICE_NAME_GIMBAL,ipv4,QString("%1").arg(port),QAbstractSocket::UnconnectedState);
        tcpSocket->close();
    }
}
void Gimbal::sendDataSlot(int value,int state)
{

    static unsigned char data[7];
    if(PRESS_STATE_RELEASED == state)
    {
        value = COMMAND_GIMBAL_TURN_STOP;
    }
    switch (value) {
    case COMMAND_GIMBAL_TURN_STOP:
        tcpSocket->write((char *)gimbalCommand[COMMAND_GIMBAL_TURN_STOP],SOCKET_GIMBAL_BUFF_SIZE);
        break;
    case COMMAND_GIMBAL_TURN_UP:
        memset(data,0,SOCKET_GIMBAL_BUFF_SIZE);
        memcpy(data,gimbalCommand[COMMAND_GIMBAL_TURN_UP],SOCKET_GIMBAL_BUFF_SIZE);
        DataPackage(data,SOCKET_GIMBAL_BUFF_SIZE,COMMAND_GIMBAL_TURN_UP);
        tcpSocket->write((char *)data,SOCKET_GIMBAL_BUFF_SIZE);
        break;
    case COMMAND_GIMBAL_TURN_DOWN:
        memset(data,0,SOCKET_GIMBAL_BUFF_SIZE);
        memcpy(data,gimbalCommand[COMMAND_GIMBAL_TURN_DOWN],SOCKET_GIMBAL_BUFF_SIZE);
        DataPackage(data,SOCKET_GIMBAL_BUFF_SIZE,COMMAND_GIMBAL_TURN_DOWN);
        tcpSocket->write((char *)data,SOCKET_GIMBAL_BUFF_SIZE);
        break;
    case COMMAND_GIMBAL_TURN_LEFT:
        memset(data,0,SOCKET_GIMBAL_BUFF_SIZE);
        memcpy(data,gimbalCommand[COMMAND_GIMBAL_TURN_LEFT],SOCKET_GIMBAL_BUFF_SIZE);
        DataPackage(data,SOCKET_GIMBAL_BUFF_SIZE,COMMAND_GIMBAL_TURN_LEFT);
        tcpSocket->write((char *)data,SOCKET_GIMBAL_BUFF_SIZE);
        break;
    case COMMAND_GIMBAL_TURN_RIGHT:
        memset(data,0,SOCKET_GIMBAL_BUFF_SIZE);
        memcpy(data,gimbalCommand[COMMAND_GIMBAL_TURN_RIGHT],SOCKET_GIMBAL_BUFF_SIZE);
        DataPackage(data,SOCKET_GIMBAL_BUFF_SIZE,COMMAND_GIMBAL_TURN_RIGHT);
        tcpSocket->write((char *)data,SOCKET_GIMBAL_BUFF_SIZE);
        break;
    case COMMAND_GIMBAL_ANGILE_SEARCH_H:
        tcpSocket->write((char *)gimbalCommand[COMMAND_GIMBAL_ANGILE_SEARCH_H],SOCKET_GIMBAL_BUFF_SIZE);
        break;
    case COMMAND_GIMBAL_ANGILE_SEARCH_V:
        tcpSocket->write((char *)gimbalCommand[COMMAND_GIMBAL_ANGILE_SEARCH_V],SOCKET_GIMBAL_BUFF_SIZE);
        break;
    case COMMAND_GIMBAL_ONECLICKZEROING:
        tcpSocket->write((char *)gimbalCommand[COMMAND_GIMBAL_ONECLICKZEROING],SOCKET_GIMBAL_BUFF_SIZE);
        break;
    case COMMAND_GIMBAL_REALTIMEACKHAUL_BEFORE_SET:
        tcpSocket->write((char *)gimbalCommand[COMMAND_GIMBAL_REALTIMEACKHAUL_BEFORE_SET],SOCKET_GIMBAL_BUFF_SIZE);
        break;
    case COMMAND_GIMBAL_REALTIMEACKHAUL_OPEN:
        tcpSocket->write((char *)gimbalCommand[COMMAND_GIMBAL_REALTIMEACKHAUL_OPEN],SOCKET_GIMBAL_BUFF_SIZE);
        break;
    case COMMAND_GIMBAL_REALTIMEACKHAUL_CLOSE:
        tcpSocket->write((char *)gimbalCommand[COMMAND_GIMBAL_REALTIMEACKHAUL_CLOSE],SOCKET_GIMBAL_BUFF_SIZE);
        break;
    case COMMAND_GIMBAL_REALTIMEACKHAUL_SET:
        tcpSocket->write((char *)gimbalCommand[COMMAND_GIMBAL_REALTIMEACKHAUL_SET],SOCKET_GIMBAL_BUFF_SIZE);
        break;
    default:
        break;
    }
    /*qDebug() <<gimbalCommand[value][0] <<" "<<gimbalCommand[value][1] <<" "<<gimbalCommand[value][2]
                  <<" "<<gimbalCommand[value][3] <<" "<<gimbalCommand[value][4] <<" "<<gimbalCommand[value][5]
                  <<" "<<gimbalCommand[value][6] ;
*/
}
void Gimbal::readData()
{
    int angle_horizontal =0.0;
    int angle_vertical =0.0;
    QByteArray array;
    unsigned char data[7];
    quint16 command = 0x0000;
    int value = 0;
    // qDebug() << "收到read";
    array = tcpSocket->read(7);
    // array = tcpSocket->readAll();
    // qDebug() << "收到read" << Qt::hex << array;

    memset(data,0,sizeof data);
    chartouchar8(array.toHex().data(),data,strlen(array.toHex().data()),sizeof data);
    command = data[2]<<8 | data[3];
    switch (command) {
    case 0X0059:
        value = (data[4] <<8 ) &0XFF00;
        value |= data[5];
        angle_horizontal = (value + value%100)/100;

        qDebug("水平角度 = %d\n",angle_horizontal);//取值范围：[0，360）
        setAngleHorizontal(angle_horizontal);
        emit sendAngleData(MESSAGE_GIMBAL_ANGLE_H,angle_horizontal);
        break;
    case 0X005B:
        value = (data[4] <<8 ) &0XFF00;
        value |= data[5];
        angle_vertical = (value + value%100)/100;
        angle_vertical = (angle_vertical>300) ? (angle_vertical - 360) : angle_vertical;
        // angle_vertical = (angle_vertical > 340)?(angle_vertical - 360):angle_vertical;

        // angle_v = (value + value%100)/100;
        qDebug("垂直角度 = %d, %d\n", angle_vertical, value);//取值范围：（-340，-360），[0，+60）
        setAngleVertical(angle_vertical);
        emit sendAngleData(MESSAGE_GIMBAL_ANGLE_V,angle_vertical);
        break;
    default:
        break;
    }
}

void Gimbal::DataPackage(unsigned char *data,int bytes,long type)
{
    unsigned char buffer[7];
    unsigned char speedvertical = 0x00;
    unsigned char speedhorizontal = 0x00;
    if((data == NULL)||(bytes != sizeof(buffer)))
    {
        printf("error data %p\n",data);
        return ;
    }
    memset(buffer,0,sizeof buffer);
    memcpy(buffer,data,sizeof buffer);
    switch(type){
    case COMMAND_GIMBAL_TURN_UP:
    case COMMAND_GIMBAL_TURN_DOWN:
        speedvertical = getSpeedVertical();
        buffer[5] &= 0x00;
        buffer[5] |= speedvertical;
        buffer[6] &= 0x00;
        buffer[6] = (buffer[1]+buffer[2]+buffer[3]+buffer[4]+buffer[5])&0xFF;
        break;
    case COMMAND_GIMBAL_TURN_LEFT:
    case COMMAND_GIMBAL_TURN_RIGHT:
        speedhorizontal = getSpeedHorizontal();
        buffer[4] &= 0x00;
        buffer[4] |= speedhorizontal;
        buffer[6] &= 0x00;
        buffer[6] = (buffer[1]+buffer[2]+buffer[3]+buffer[4]+buffer[5])&0xFF;
        break;
    }
    memcpy(data,buffer,sizeof buffer);
    return ;

}
void Gimbal::chartouchar8(const char *src,unsigned char *dst,unsigned char srclen,unsigned char dstlen)
{
    char srcdata[14];
    unsigned char dstdata[7];
    if(srclen != (sizeof srcdata ))
    {
        return;
    }
    if(src == NULL||dst == NULL||srclen != (sizeof srcdata )||dstlen != (sizeof dstdata ))
    {
        qDebug() << "chartouchar8 error input";
        return ;
    }
    memset(srcdata,0,sizeof srcdata);
    memset(dstdata,0,sizeof dstdata);
    qstrncpy(srcdata,src,sizeof srcdata + 1);
    for(int i = 0,j = 0;i < 7;i++,j+=2)
    {
        if( (('0' <= srcdata[j])&&(srcdata[j] <= '9'))
            ||(('a' <= srcdata[j])&&(srcdata[j] <= 'f'))
            ||(('A' <= srcdata[j])&&(srcdata[j] <= 'F')))
        {
            if(('0' <= srcdata[j])&&(srcdata[j] <= '9'))
            {
                srcdata[j] = srcdata[j] - '0';
            }
            else if( (('a' <= srcdata[j])&&(srcdata[j] <= 'f')) )
            {
                srcdata[j] = srcdata[j] - 'a' + 10;
            }
            else if( (('A' <= srcdata[j])&&(srcdata[j] <= 'F')) )
            {
                srcdata[j] = srcdata[j] - 'A' + 10;
            }
            else
            {}
            if(('0' <= srcdata[j+1])&&(srcdata[j+1] <= '9'))
            {
                srcdata[j+1] = srcdata[j+1] - '0';
            }
            else if( (('a' <= srcdata[j+1])&&(srcdata[j+1] <= 'f')) )
            {
                srcdata[j+1] = srcdata[j+1] - 'a' + 10;
            }
            else if( (('A' <= srcdata[j+1])&&(srcdata[j+1] <= 'F')) )
            {
                srcdata[j+1] = srcdata[j+1] - 'A' + 10;
            }
            else
            {}
            dstdata[i] = srcdata[j] * 16 + srcdata[j+1];
            //qDebug("dstdata[%d]:%d,srcdata[%d]:%d,srcdata[%d]:%d.",i,dstdata[i],j,srcdata[j],j+1,srcdata[j+1]);
        }
    }
    memcpy(dst,dstdata,sizeof dstdata);
}
float Gimbal::getAngleHorizontal()
{
    return angle_horizontal;
}
float Gimbal::getAngleVertical()
{
    return angle_vertical;
}
void Gimbal::setAngleHorizontal(int value)
{
    angle_horizontal = value;
}
void Gimbal::setAngleVertical(int value)
{
    angle_vertical = value;
}
quint8 Gimbal::getSpeedHorizontal()
{
    return speed_horizontal;
}
quint8 Gimbal::getSpeedVertical()
{
    return speed_vertical;
}
void Gimbal::setSpeedHorizontal(quint8 value)
{
    speed_horizontal = value;
}
void Gimbal::setSpeedVertical(quint8 value)
{
    speed_vertical = value;
}
void Gimbal::VspeedSliderValueChanged(int value)
{
    quint8  speed_vertical= 0x00;
     speed_vertical= speedarray[value];
    setSpeedVertical(speed_vertical);
}
void Gimbal::HspeedSliderValueChanged(int value)
{
    quint8  speed_horizontal = 0x00;
     speed_horizontal = speedarray[value];
    setSpeedHorizontal(speed_horizontal);
}
void Gimbal::btnRealtimeAckhaulOpenClicked()
{
    sendDataSlot(COMMAND_GIMBAL_REALTIMEACKHAUL_OPEN,SOCKET_GIMBAL_BUFF_SIZE);
}
void Gimbal::btnRealtimeAckhaulCloseClicked()
{
    sendDataSlot(COMMAND_GIMBAL_REALTIMEACKHAUL_CLOSE,SOCKET_GIMBAL_BUFF_SIZE);
}
void Gimbal::comboBox_RealtimeAckhaulChange(const QString &arg1)
{
    quint8 data;
    quint8 array[7];
    data = (quint8)arg1.toInt();
    memset(array,0,SOCKET_GIMBAL_BUFF_SIZE);
    memcpy(array,gimbalCommand[COMMAND_GIMBAL_REALTIMEACKHAUL_SET],SOCKET_GIMBAL_BUFF_SIZE);
    array[5] &= 0x00;
    array[5] |= data;
    array[6] = (array[1]+array[2]+array[3]+array[4]+array[5])&0XFF;
    tcpSocket->write((char *)array,SOCKET_GIMBAL_BUFF_SIZE);
}
void Gimbal::btnOneClickZeroingClicked()
{
    sendDataSlot(COMMAND_GIMBAL_ONECLICKZEROING,SOCKET_GIMBAL_BUFF_SIZE);
}
void Gimbal::handle_checkBoxRealtimeAckhaulOpenSet(bool checkstate)
{
    qDebug()<< checkstate;
    if(checkstate)
    {
        sendDataSlot(COMMAND_GIMBAL_REALTIMEACKHAUL_BEFORE_SET,SOCKET_GIMBAL_BUFF_SIZE);
    }
}


