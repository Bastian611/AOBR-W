#include "inc/acousticcontrol.h"
Acousticcontrol::Acousticcontrol(QObject *parent) : QObject(parent)
{
    qDebug() << "Acousticcontrol init.";
    /*****/
    jsondata = new JsonData();
    start();
    CommandJsonFileInit();
    onlineTimerInit();

}
void Acousticcontrol::start()
{

    connect(this,&Acousticcontrol::startSignal,this,&Acousticcontrol::Init);
    qDebug() << "Acousticcontrol start";
}
void Acousticcontrol::Init()
{
    ThreadName = this->objectName();
    qDebug()<< ThreadName;
    IPInit();
    tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost(ipv4,9527);
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(connectedSlot()));
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(handleDisconnected()));
    connect(tcpSocket,SIGNAL(errorOccurred(QAbstractSocket::SocketError)),
            this,SLOT(handleError(QAbstractSocket::SocketError)));
    SetCseq(1);
    SetCurrentPlayerIndex("0");
    CurrentPlayMode = PALY_MODE_IDLE;
}
void Acousticcontrol::connectedSlot()
{
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readData()));
    if(operator==(ThreadName,"Acousticcontrol"))
    {
        emit sig_ConnectState(DEVICE_NAME_ACOUSTICCONTROL,ipv4,QString("%1").arg(port),QAbstractSocket::ConnectedState);
    }
    else
    {}
    qDebug() << "连接成功";
    //启动常连接定时器
    timer->start();
}
//正常操作断开连接
void Acousticcontrol::handleDisconnected()
{
    qDebug() << "Acousticcontrol断开连接";
    disconnect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readData()));
    disconnect(tcpSocket,SIGNAL(connected()),this,SLOT(connectedSlot()));
}
//异常产生断开连接
void Acousticcontrol::handleError(QAbstractSocket::SocketError ErrorNumber)
{
    qDebug() << "发生错误，断开连接"<<ErrorNumber;
    disconnect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readData()));
    disconnect(tcpSocket,SIGNAL(connected()),this,SLOT(connectedSlot()));
    tcpSocket->close();
    if(operator==(ThreadName,"Acousticcontrol"))
    {
        emit sig_ConnectState(DEVICE_NAME_ACOUSTICCONTROL,ipv4,QString("%1").arg(port),QAbstractSocket::ClosingState);
    }
    else
    {}

}
void Acousticcontrol::readData()
{
    QByteArray array;
    array = tcpSocket->readAll();
    array = jsondata->ByteArrayTrimmed(array);
    //剔除自定义末尾标识符
    JsonParsing(array);
}
void Acousticcontrol::IPInit()
{
    ipv4 = "";
    port = 0;
    qDebug()<<"Acousticcontrol:" << ThreadName;
    QJsonObject tempjsonobject,tempsubjsonobject;
    QFile file("./IP.json");
    tempjsonobject = QJsonObject();
    tempsubjsonobject = QJsonObject();
    if(file.exists())
    {
        jsondata->ObjectReadFromFile(&tempjsonobject,"./IP.json");
        tempsubjsonobject = jsondata->getSubObject(&tempjsonobject,ThreadName);
        ipv4 = jsondata->GetObjectValueQString(&tempsubjsonobject,"ip");
        port = jsondata->GetObjectValueQString(&tempsubjsonobject,"port").toUShort();
        if(ipv4 == QString())
        {
            if(operator==(ThreadName,"Acousticcontrol"))
            {
                ipv4 = "192.168.1.200";
                port = 9527;
                jsondata->ObjectInsertData(&tempsubjsonobject,"ip",ipv4);
                jsondata->ObjectInsertData(&tempsubjsonobject,"port",QString("%1").arg(port));
                jsondata->ObjectInsertSubObject(&tempjsonobject,ThreadName,&tempsubjsonobject);
                jsondata->ObjectWriteToFile(&tempjsonobject,"./IP.json");
                emit sig_ConnectState(DEVICE_NAME_ACOUSTICCONTROL,ipv4,QString("%1").arg(port),
                                      QAbstractSocket::UnconnectedState);
            }
            else
            {}
        }
        else
        {}
        if(operator==(ThreadName,"Acousticcontrol"))
        {
            emit sig_ConnectState(DEVICE_NAME_ACOUSTICCONTROL,ipv4,QString("%1").arg(port),
                                  QAbstractSocket::UnconnectedState);
        }
        else
        {}

    }
    else
    {
        if(operator==(ThreadName,"Acousticcontrol"))
        {
            ipv4 = "192.168.1.200";
            port = 9527;
            jsondata->ObjectInsertData(&tempsubjsonobject,"ip",ipv4);
            jsondata->ObjectInsertData(&tempsubjsonobject,"port",QString("%1").arg(port));
            jsondata->ObjectInsertSubObject(&tempjsonobject,ThreadName,&tempsubjsonobject);
            tempsubjsonobject = QJsonObject();
            jsondata->ObjectInsertData(&tempsubjsonobject,"ip","192.168.1.201");
            jsondata->ObjectInsertData(&tempsubjsonobject,"port",QString("%1").arg(9527));
            jsondata->ObjectInsertSubObject(&tempjsonobject,"Acousticcontrol_2",&tempsubjsonobject);
            jsondata->ObjectWriteToFile(&tempjsonobject,"./IP.json");
            emit sig_ConnectState(DEVICE_NAME_ACOUSTICCONTROL,ipv4,QString("%1").arg(port),QAbstractSocket::UnconnectedState);
        }
        else
        {}

    }
}
void Acousticcontrol::btnConnectClicked()
{
    if(tcpSocket->state() == QAbstractSocket::UnconnectedState)
    {
        //未连接时
        qDebug() << "Acousticcontrol UnconnectedState";
        //从文件中读取ip地址
        QJsonObject tempjsonobject,tempsubjsonobject;
        QFile file("./IP.json");
        if(file.exists())
        {
            jsondata->ObjectReadFromFile(&tempjsonobject,"./IP.json");
            tempsubjsonobject = jsondata->getSubObject(&tempjsonobject,ThreadName);
            ipv4 = jsondata->GetObjectValueQString(&tempsubjsonobject,"ip");
            port = jsondata->GetObjectValueQString(&tempsubjsonobject,"port").toUShort();
            tcpSocket->connectToHost(ipv4,port);
            connect(tcpSocket,SIGNAL(connected()),this,SLOT(connectedSlot()));
            if(operator==(ThreadName,"Acousticcontrol"))
            {
               emit sig_ConnectState(DEVICE_NAME_ACOUSTICCONTROL,ipv4,QString("%1").arg(port),QAbstractSocket::ConnectingState);
            }
            else
            {}
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
        qDebug() << "Acousticcontrol ConnectedState";
        if(operator==(ThreadName,"Acousticcontrol"))
        {
            emit sig_ConnectState(DEVICE_NAME_ACOUSTICCONTROL,ipv4,QString("%1").arg(port),QAbstractSocket::UnconnectedState);
        }
        else
        {}
        tcpSocket->close();
    }
}
void Acousticcontrol::onlineTimerInit()
{
    timer = new QTimer(this);
    timer->setInterval(1000*30);
    connect(timer,SIGNAL(timeout()),this,SLOT(onlineTimeout()));
}
void Acousticcontrol::onlineTimeout()
{
    QByteArray array = QString("{\"command\":\"online\",\"cseq\":\"%1\"}\r\n\r\n").arg(GetCseq()).toUtf8();
    CseqSelfIncrease();
    if(tcpSocket->isWritable())
        tcpSocket->write(array);
}
void Acousticcontrol::CommandJsonFileInit()
{
    QJsonObject tempjsonobject,tempsubjsonobject;
    //检查文件是否存在，存在则从文件中读取
    //不存在则创建新文件
    QFile file("./command.json");
    if(file.exists())
    {
        jsondata->ObjectReadFromFile(&g_JsonObject,"./command.json");
        qDebug()<< "json file Read success.";
        return ;
    }
    else
    {
        jsondata->ObjectInsertData(&tempjsonobject,"command","online");
        jsondata->ObjectInsertData(&tempjsonobject,"cseq","1");
        jsondata->ObjectInsertSubObject(&g_JsonObject,"常连接",&tempjsonobject);
        tempjsonobject = QJsonObject();
        jsondata->ObjectInsertData(&tempjsonobject,"command","model_change");
        jsondata->ObjectInsertData(&tempjsonobject,"cseq","1");
        jsondata->ObjectInsertData(&tempjsonobject, "model","idle");
        jsondata->ObjectInsertSubObject(&tempsubjsonobject,"空闲模式",&tempjsonobject);
        tempjsonobject = QJsonObject();
        jsondata->ObjectInsertData(&tempjsonobject,"command","model_change");
        jsondata->ObjectInsertData(&tempjsonobject,"cseq","1");
        jsondata->ObjectInsertData(&tempjsonobject, "model","player");
        jsondata->ObjectInsertSubObject(&tempsubjsonobject,"普通播放器模式",&tempjsonobject);
        tempjsonobject = QJsonObject();
        jsondata->ObjectInsertData(&tempjsonobject,"command","model_change");
        jsondata->ObjectInsertData(&tempjsonobject,"cseq","1");
        jsondata->ObjectInsertData(&tempjsonobject, "model","one_key");
        jsondata->ObjectInsertSubObject(&tempsubjsonobject,"一键驱散模式",&tempjsonobject);
        tempjsonobject = QJsonObject();
        jsondata->ObjectInsertData(&tempjsonobject,"command","model_change");
        jsondata->ObjectInsertData(&tempjsonobject,"cseq","1");
        jsondata->ObjectInsertData(&tempjsonobject, "model","mic_broadcast");
        jsondata->ObjectInsertSubObject(&tempsubjsonobject,"远程接口喊话模式",&tempjsonobject);
        tempjsonobject = QJsonObject();
        jsondata->ObjectInsertData(&tempjsonobject,"command","model_change");
        jsondata->ObjectInsertData(&tempjsonobject,"cseq","1");
        jsondata->ObjectInsertData(&tempjsonobject, "model","record");
        jsondata->ObjectInsertSubObject(&tempsubjsonobject,"录音喊话模式",&tempjsonobject);
        tempjsonobject = QJsonObject();
        jsondata->ObjectInsertData(&tempjsonobject,"command","model_change");
        jsondata->ObjectInsertData(&tempjsonobject,"cseq","1");
        jsondata->ObjectInsertData(&tempjsonobject, "model","input_sound");
        jsondata->ObjectInsertSubObject(&tempsubjsonobject,"外部音源输入模式",&tempjsonobject);
        jsondata->ObjectInsertSubObject(&g_JsonObject,"切换播放格式",&tempsubjsonobject);
        tempjsonobject = QJsonObject();
        tempsubjsonobject = QJsonObject();
        jsondata->ObjectInsertData(&tempjsonobject,"command","get_play_list");
        jsondata->ObjectInsertData(&tempjsonobject,"cseq","1");
        jsondata->ObjectInsertSubObject(&tempsubjsonobject,"获取播放列表",&tempjsonobject);
        tempjsonobject = QJsonObject();
        jsondata->ObjectInsertData(&tempjsonobject,"command","reload_play_list");
        jsondata->ObjectInsertData(&tempjsonobject,"cseq","1");
        jsondata->ObjectInsertSubObject(&tempsubjsonobject,"更新播放列表",&tempjsonobject);
        jsondata->ObjectInsertSubObject(&g_JsonObject,"获取MP3播放列表",&tempsubjsonobject);
        tempjsonobject = QJsonObject();
        tempsubjsonobject = QJsonObject();
        jsondata->ObjectInsertData(&tempjsonobject,"command","start_play");
        jsondata->ObjectInsertData(&tempjsonobject,"cseq","1");
        jsondata->ObjectInsertData(&tempjsonobject,"index","0");
        jsondata->ObjectInsertSubObject(&tempsubjsonobject,"开始播放指令",&tempjsonobject);
        tempjsonobject = QJsonObject();
        jsondata->ObjectInsertData(&tempjsonobject,"command","stop_play");
        jsondata->ObjectInsertData(&tempjsonobject,"cseq","1");
        jsondata->ObjectInsertSubObject(&tempsubjsonobject,"暂停指令",&tempjsonobject);
        tempjsonobject = QJsonObject();
        jsondata->ObjectInsertData(&tempjsonobject,"command","next_play");
        jsondata->ObjectInsertData(&tempjsonobject,"cseq","1");
        jsondata->ObjectInsertSubObject(&tempsubjsonobject,"下一首指令",&tempjsonobject);
        tempjsonobject = QJsonObject();
        jsondata->ObjectInsertData(&tempjsonobject,"command","pre_play");
        jsondata->ObjectInsertData(&tempjsonobject,"cseq","1");
        jsondata->ObjectInsertSubObject(&tempsubjsonobject,"上一首指令",&tempjsonobject);
        tempjsonobject = QJsonObject();
        jsondata->ObjectInsertData(&tempjsonobject,"command","repeat_play");
        jsondata->ObjectInsertData(&tempjsonobject,"cseq","1");
        jsondata->ObjectInsertData(&tempjsonobject,"index","-1");
        jsondata->ObjectInsertSubObject(&tempsubjsonobject,"单曲循环指令",&tempjsonobject);
        jsondata->ObjectInsertSubObject(&g_JsonObject,"MP3播放模式",&tempsubjsonobject);
        tempjsonobject = QJsonObject();
        tempsubjsonobject = QJsonObject();
        jsondata->ObjectInsertData(&tempjsonobject,"command","one_key");
        jsondata->ObjectInsertData(&tempjsonobject,"cseq","1");
        jsondata->ObjectInsertData(&tempjsonobject,"index","/xmedia/onekey/alarm.mp3");
        jsondata->ObjectInsertSubObject(&tempsubjsonobject,"播放指定路径音频文件",&tempjsonobject);
        tempjsonobject = QJsonObject();
        jsondata->ObjectInsertData(&tempjsonobject,"command","one_key");
        jsondata->ObjectInsertData(&tempjsonobject,"cseq","1");
        jsondata->ObjectInsertData(&tempjsonobject,"index","1");
        jsondata->ObjectInsertSubObject(&tempsubjsonobject,"播放文件列表文件",&tempjsonobject);
        jsondata->ObjectInsertSubObject(&g_JsonObject,"一键驱散模式",&tempsubjsonobject);
        tempjsonobject = QJsonObject();
        tempsubjsonobject = QJsonObject();
        jsondata->ObjectInsertData(&tempjsonobject,"command","mp3_stream_play");
        jsondata->ObjectInsertData(&tempjsonobject,"cseq","1");
        jsondata->ObjectInsertData(&tempjsonobject,"mp3_len","23454");
        jsondata->ObjectInsertSubObject(&tempsubjsonobject,"上传mp3文件播放",&tempjsonobject);
        jsondata->ObjectInsertSubObject(&g_JsonObject,"实时文件播放",&tempsubjsonobject);
        tempjsonobject = QJsonObject();
        tempsubjsonobject = QJsonObject();
        jsondata->ObjectInsertData(&tempjsonobject,"command","play_vol");
        jsondata->ObjectInsertData(&tempjsonobject,"cseq","1");
        jsondata->ObjectInsertData(&tempjsonobject,"vol","20");
        jsondata->ObjectInsertSubObject(&tempsubjsonobject,"播放音量控制",&tempjsonobject);
        tempjsonobject = QJsonObject();
        jsondata->ObjectInsertData(&tempjsonobject,"command","cap_vol");
        jsondata->ObjectInsertData(&tempjsonobject,"cseq","1");
        jsondata->ObjectInsertData(&tempjsonobject,"vol","20");
        jsondata->ObjectInsertSubObject(&tempsubjsonobject,"采集音量控制",&tempjsonobject);
        tempjsonobject = QJsonObject();
        jsondata->ObjectInsertData(&tempjsonobject,"command","get_vol");
        jsondata->ObjectInsertData(&tempjsonobject,"cseq","1");
        jsondata->ObjectInsertSubObject(&tempsubjsonobject,"读取采集音量和播放音量",&tempjsonobject);
        jsondata->ObjectInsertSubObject(&g_JsonObject,"播放和采集音量",&tempsubjsonobject);
        tempjsonobject = QJsonObject();
        tempsubjsonobject = QJsonObject();
        jsondata->ObjectInsertData(&tempjsonobject,"command","get_status");
        jsondata->ObjectInsertData(&tempjsonobject,"cseq","1");
        jsondata->ObjectInsertSubObject(&tempsubjsonobject,"获取当前状态",&tempjsonobject);
        jsondata->ObjectInsertSubObject(&g_JsonObject,"获取当前状态",&tempsubjsonobject);
        jsondata->ObjectWriteToFile(&g_JsonObject,"./command.json");
        qDebug()<< "json file Create success.";
    }
}
void Acousticcontrol::JsonParsing(QByteArray array)
{
    QJsonObject jsonboject;
    QString key;
    QJsonValue value;
    QString command;
    QString currentPlayerMode;
    //int cseq;
    int code;
    int play_vol;
    int cap_vol;
    jsonboject = jsondata->ByteArrayToObject(array);
    if(jsonboject.isEmpty())
    {
        qDebug()<<"Socket_StrongSoundTCP::JsonParsing empty jsonboject";
        return;
    }
    QStringList keys = jsonboject.keys();
    for(int i = 0; i<keys.size();i++)
    {
        key = keys.at(i);
        if(operator==(key,"command"))
        {
            value = jsonboject.value(key);
            if(value.isString())
            {
                command = value.toString();
                break;
            }
        }
        else
        {}
    }
    if(QString(command).isEmpty())
    {
        return ;
    }
    if(operator==(command,"reload_play_list"))
    {
        for(int i = 0; i<keys.size();i++)
        {
            key = keys.at(i);
            if(operator==(key,"code"))
            {
                value = jsonboject.value(key);
                if(value.isString())
                {
                    code = value.toString().toInt();
                    SetCode(code);
                    //qDebug() << GetCode();
                    continue;
                }
            }
            else
            {}
        }
    }
    else if(operator==(command,"get_play_list"))
    {
        for(int i = 0; i<keys.size();i++)
        {
            key = keys.at(i);
            if(operator==(key,"play_list"))
            {
                value = jsonboject.value(key);
                if(value.isArray())
                {
                    QJsonArray array = value.toArray();
                    handle_load_play_list(&array);
                    continue;
                }
            }
            else
            {}
        }
    }
    else if(operator==(command,"start_record"))
    {
        for(int i = 0; i<keys.size();i++)
        {
            key = keys.at(i);
            if(operator==(key,"code"))
            {
                value = jsonboject.value(key);
                if(value.isString())
                {
                    code = value.toString().toInt();
                    SetCode(code);
                    qDebug() << GetCode();
                    continue;
                }
            }
            else
            {}
        }
    }
    else if(operator==(command,"post_vol"))
    {
        for(int i = 0; i<keys.size();i++)
        {
            key = keys.at(i);
            if(operator==(key,"play_vol"))
            {
                value = jsonboject.value(key);
                if(value.isString())
                {
                    play_vol = value.toString().toInt();
                    SetPlayVolume(play_vol);
                }
            }
            else if(operator==(key,"cap_vol"))
            {
                value = jsonboject.value(key);
                if(value.isString())
                {
                    cap_vol = value.toString().toInt();
                    SetCollectionVolume(cap_vol);
                }
            }
            else
            {}
        }
    }
    else if(operator==(command,"post_status"))
    {
        for(int i = 0; i<keys.size();i++)
        {
            key = keys.at(i);
            if(operator==(key,"model"))
            {
                value = jsonboject.value(key);
                if(value.isString())
                {
                    currentPlayerMode = value.toString();
                    continue;
                }
            }
            else
            {}
        }
    }
    else
    {}
    jsondata->ObjectWriteToFile(&g_JsonObject,"./command.json");
}
void Acousticcontrol::SetPlayVolume(int volume)
{
    int tempVolume;
    QString tempstringVolume;
    QJsonObject subjsonobject,subjsonobjectPlayVolum;
    tempVolume = volume;
    subjsonobject = jsondata->getSubObject(&g_JsonObject,"播放和采集音量");
    subjsonobjectPlayVolum = jsondata->getSubObject(&subjsonobject,"播放音量控制");
    tempstringVolume = QString("%1").arg(tempVolume);
    jsondata->ObjectInsertData(&subjsonobjectPlayVolum,"vol",tempstringVolume);
    jsondata->ObjectInsertSubObject(&subjsonobject,"播放音量控制",&subjsonobjectPlayVolum);
    jsondata->ObjectInsertSubObject(&g_JsonObject,"播放和采集音量",&subjsonobject);
}
int Acousticcontrol::GetPlayVolume()
{
    int tempVolume = 0;
    QString tempstringVolume;
    QJsonObject subjsonobject,subjsonobjectPlayVolume;
    subjsonobject = jsondata->getSubObject(&g_JsonObject,"播放和采集音量");
    subjsonobjectPlayVolume = jsondata->getSubObject(&subjsonobject,"播放音量控制");
    tempstringVolume =jsondata->GetObjectValueQString(&subjsonobjectPlayVolume,"vol");
    tempVolume = tempstringVolume.toInt();
    return tempVolume;
}
void Acousticcontrol::SetCollectionVolume(int volume)
{
    int tempVolume;
    QString tempstringVolume;
    QJsonObject subjsonobject,subjsonobjectCollectionVolum;
    tempVolume = volume;
    subjsonobject = jsondata->getSubObject(&g_JsonObject,"播放和采集音量");
    subjsonobjectCollectionVolum = jsondata->getSubObject(&subjsonobject,"采集音量控制");
    tempstringVolume = QString("%1").arg(tempVolume);
    jsondata->ObjectInsertData(&subjsonobjectCollectionVolum,"vol",tempstringVolume);
    jsondata->ObjectInsertSubObject(&subjsonobject,"采集音量控制",&subjsonobjectCollectionVolum);
    jsondata->ObjectInsertSubObject(&g_JsonObject,"播放和采集音量",&subjsonobject);
}
int  Acousticcontrol::GetCollectionVolume()
{
    int tempVolume = 0;
    QString tempstringVolume;
    QJsonObject subjsonobject,subjsonobjectCollectionVolum;
    subjsonobject = jsondata->getSubObject(&g_JsonObject,"播放和采集音量");
    subjsonobjectCollectionVolum = jsondata->getSubObject(&subjsonobject,"采集音量控制");
    tempstringVolume =jsondata->GetObjectValueQString(&subjsonobjectCollectionVolum,"vol");
    tempVolume = tempstringVolume.toInt();
    return tempVolume;
}
void Acousticcontrol::SetCseq(int cseq)
{
    mutex.lock();
    g_Cseq = cseq;
    mutex.unlock();
}
int  Acousticcontrol::GetCseq()
{
    mutex.lock();
    int cseq = 1;
    cseq = g_Cseq;
    mutex.unlock();
    return cseq;
}
void Acousticcontrol::CseqSelfIncrease()
{
    mutex.lock();
    ++g_Cseq;
    mutex.unlock();
}
void Acousticcontrol::SetCode(int code)
{
    g_Code = code;
}
int  Acousticcontrol::GetCode()
{
    int code = 0;
    code = g_Code;
    return code;
}
void Acousticcontrol::SetCurrentPlayerIndex(QString currentIndex)
{
    g_CurrentPlayerIndex = currentIndex;
}
QString  Acousticcontrol::GetCurrentPlayerIndex()
{
    QString currentIndex;
    currentIndex = g_CurrentPlayerIndex;
    return currentIndex;
}
//设置歌曲列表长度
void Acousticcontrol::SetCurrentPlayerIndex_MAX(quint64 currentIndex_MAX)
{
    g_CurrentPlayerIndex_MAX = currentIndex_MAX;
}
//获取歌曲列表长度
quint64  Acousticcontrol::GetCurrentPlayerIndex_MAX()
{
    quint64 currentIndex_MAX;
    currentIndex_MAX = g_CurrentPlayerIndex_MAX;
    return currentIndex_MAX;
}
void Acousticcontrol::playerListUpdate()
{
    QJsonObject jsonobject,subjsonobject,thirdjsonobject;
    QByteArray array;
    jsonobject = jsondata->getSubObject(&g_JsonObject,"获取MP3播放列表");
    subjsonobject = jsondata->getSubObject(&jsonobject,"更新播放列表");
    array = jsondata->ObjectToByteArray(&subjsonobject);
    array = jsondata->ByteArrayAppend(array);
    tcpSocket->write(array);
    subjsonobject = QJsonObject();//清空数据
    subjsonobject = jsondata->getSubObject(&jsonobject,"获取播放列表");
    CseqSelfIncrease();
    jsondata->ObjectInsertData(&subjsonobject,"cseq",GetCseq());
    array = jsondata->ObjectToByteArray(&subjsonobject);
    array = jsondata->ByteArrayAppend(array);
    tcpSocket->write(array);
}
void Acousticcontrol::handle_load_play_list(QJsonArray *jsonarray)
{
    QJsonArray jsonArray = *jsonarray;
    QJsonObject JsonObject;
    QString index;//字符串数组成员1
    QString name;//字符串数组成员2
    QList <QString> listItem;//一维字符串数组
    QMap <int, QList<QString> > listMap;//二维字符串数组
    //从数组中获取object
    for(int i = 0;i< jsonArray.size();i++)
    {
        if(jsonArray[i].isObject())
        {
            JsonObject = jsonArray[i].toObject();
            index = jsondata->GetObjectValueQString(&JsonObject,"index");
            name = jsondata->GetObjectValueQString(&JsonObject,"name");
            name = jsondata->QStringTrimmedMid(name,"/xmedia/mp3/");//剔除目录前缀
            listItem.clear();
            listItem.push_back(index);
            listItem.push_back(name);
            listMap.insert(i,listItem);
        }
    }
    //取数据
    QList<QString> sendlist;
    sendlist.clear();
    emit sig_listWidgetClear();//清除列表
    for (int i = 0; i < listMap.keys().size(); ++i) {
        sendlist = listMap.value(i);
        emit sig_listWidgetAddItem(sendlist[1]);
    }
    SetCurrentPlayerIndex_MAX(listMap.keys().size());
}
void Acousticcontrol::Play()
{
    //播放
    if(CurrentPlayMode != PALY_MODE_PLAYER)
    {
        CurrentPlayMode = PALY_MODE_PLAYER;
        QByteArray Broadcastarray;
        Broadcastarray = QString("{\"command\":\"model_change\",\"cseq\":\"%1\",\"model\":\"player\"}\r\n\r\n")
                             .arg(GetCseq()).toUtf8();
        CseqSelfIncrease();
        tcpSocket->write(Broadcastarray);
    }
    QList<QByteArray> PlayList;
    PlayList << QString("{\"command\":\"start_play\",\"cseq\":\"%1\",\"index\":\"%2\"}\r\n\r\n").arg(GetCseq()).arg(GetCurrentPlayerIndex()).toUtf8();
    CseqSelfIncrease();
    tcpSocket->write(PlayList[0]);
}

void Acousticcontrol::Pause()
{
    //暂停播放
    if(CurrentPlayMode != PALY_MODE_PLAYER)
    {
        CurrentPlayMode = PALY_MODE_PLAYER;
        QByteArray Broadcastarray;
        Broadcastarray = QString("{\"command\":\"model_change\",\"cseq\":\"%1\",\"model\":\"player\"}\r\n\r\n")
                             .arg(GetCseq()).toUtf8();
        CseqSelfIncrease();
        tcpSocket->write(Broadcastarray);
    }
    QByteArray array;
    static bool flag = true;
    if(flag)
    {
        array = QString("{\"command\":\"stop_play\",\"cseq\":\"%1\"}\r\n\r\n").arg(GetCseq()).toUtf8();
        CseqSelfIncrease();
        tcpSocket->write(array);
        flag = !flag;
    }
    else
    {
        array = QString("{\"command\":\"start_play\",\"cseq\":\"%1\",\"index\":\"%2\"}\r\n\r\n").arg(GetCseq()).arg(-1).toUtf8();
        CseqSelfIncrease();
        tcpSocket->write(array);
        flag = !flag;
    }
}
void Acousticcontrol::SongPrevious()
{
    //前一文件
    if(CurrentPlayMode != PALY_MODE_PLAYER)
    {
        CurrentPlayMode = PALY_MODE_PLAYER;
        QByteArray Broadcastarray;
        Broadcastarray = QString("{\"command\":\"model_change\",\"cseq\":\"%1\",\"model\":\"player\"}\r\n\r\n")
                             .arg(GetCseq()).toUtf8();
        CseqSelfIncrease();
        tcpSocket->write(Broadcastarray);
    }
    quint64 currentIndex;
    QByteArray array;
    array = QString("{\"command\":\"pre_play\",\"cseq\":\"%1\"}\r\n\r\n").arg(GetCseq()).toUtf8();
    CseqSelfIncrease();
    currentIndex = GetCurrentPlayerIndex().toInt();
    currentIndex--;
    if(currentIndex > GetCurrentPlayerIndex_MAX())//数值翻转
    {
        currentIndex = GetCurrentPlayerIndex_MAX() - 1;
        SetCurrentPlayerIndex(QString("%1").arg(currentIndex));
    }
    else
    {
        SetCurrentPlayerIndex(QString("%1").arg(currentIndex));
    }
    emit sig_SongPrevious(GetCurrentPlayerIndex());
    tcpSocket->write(array);
}
void Acousticcontrol::SongNext()
{
    //下一文件
    if(CurrentPlayMode != PALY_MODE_PLAYER)
    {
        CurrentPlayMode = PALY_MODE_PLAYER;
        QByteArray Broadcastarray;
        Broadcastarray = QString("{\"command\":\"model_change\",\"cseq\":\"%1\",\"model\":\"player\"}\r\n\r\n")
                             .arg(GetCseq()).toUtf8();
        CseqSelfIncrease();
        tcpSocket->write(Broadcastarray);
    }
    quint64 currentIndex;
    QByteArray array;
    array = QString("{\"command\":\"next_play\",\"cseq\":\"%1\"}\r\n\r\n").arg(GetCseq()).toUtf8();
    CseqSelfIncrease();
    currentIndex = GetCurrentPlayerIndex().toInt();
    currentIndex++;
    if(currentIndex > (GetCurrentPlayerIndex_MAX() - 1))
    {
        currentIndex = 0;
        SetCurrentPlayerIndex(QString("%1").arg(currentIndex));
    }
    else
    {
        SetCurrentPlayerIndex(QString("%1").arg(currentIndex));
    }
    emit sig_SongPrevious(GetCurrentPlayerIndex());
    tcpSocket->write(array);
}
void Acousticcontrol::SongSinglecycle()
{
    //当前歌曲单曲循环
    if(CurrentPlayMode != PALY_MODE_PLAYER)
    {
        CurrentPlayMode = PALY_MODE_PLAYER;
        QByteArray Broadcastarray;
        Broadcastarray = QString("{\"command\":\"model_change\",\"cseq\":\"%1\",\"model\":\"player\"}\r\n\r\n")
                             .arg(GetCseq()).toUtf8();
        CseqSelfIncrease();
        tcpSocket->write(Broadcastarray);
    }

    QByteArray array;
    array = QString("{\"command\":\"repeat_play\",\"cseq\":\"%1\",\"index\":\"%2\"}\r\n\r\n")
                .arg(GetCseq()).arg(-1).toUtf8();
    CseqSelfIncrease();
    tcpSocket->write(array);
}
void Acousticcontrol::SliderPLayerVolumeChanged(int value)
{
    QByteArray array;
    array = QString("{\"command\":\"play_vol\",\"cseq\":\"%1\",\"vol\":\"%2\"}\r\n\r\n")
                     .arg(GetCseq()).arg(value).toUtf8();
    CseqSelfIncrease();
    tcpSocket->write(array);
}
void Acousticcontrol::SliderCapVolumeChanged(int value)
{
    QByteArray array;
    array = QString("{\"command\":\"cap_vol\",\"cseq\":\"%1\",\"vol\":\"%2\"}\r\n\r\n")
                     .arg(GetCseq()).arg(value).toUtf8();
    CseqSelfIncrease();
    tcpSocket->write(array);
}
void Acousticcontrol::SongListdoubleClick(const QModelIndex &modelIndex)
{
    if(CurrentPlayMode != PALY_MODE_PLAYER)
    {
        CurrentPlayMode = PALY_MODE_PLAYER;
        QByteArray Broadcastarray;
        Broadcastarray = QString("{\"command\":\"model_change\",\"cseq\":\"%1\",\"model\":\"player\"}\r\n\r\n")
                             .arg(GetCseq()).toUtf8();
        CseqSelfIncrease();
        tcpSocket->write(Broadcastarray);
    }
    int index = modelIndex.row();
    SetCurrentPlayerIndex(QString("%1").arg(index));
    QList<QByteArray> PlayList;
    PlayList << QString("{\"command\":\"model_change\",\"cseq\":\"%1\",\"model\":\"player\"}\r\n\r\n").arg(GetCseq()).toUtf8();
    CseqSelfIncrease();
    PlayList << QString("{\"command\":\"start_play\",\"cseq\":\"%1\",\"index\":\"%2\"}\r\n\r\n").arg(GetCseq()).arg(GetCurrentPlayerIndex()).toUtf8();
    CseqSelfIncrease();
    tcpSocket->write(PlayList[0]);
    tcpSocket->write(PlayList[1]);
}
void Acousticcontrol::OneKeyClicked()
{
    if(CurrentPlayMode != PALY_MODE_ONE_KEY)
    {
        CurrentPlayMode = PALY_MODE_ONE_KEY;
        QByteArray Broadcastarray;
        Broadcastarray = QString("{\"command\":\"model_change\",\"cseq\":\"%1\",\"model\":\"one_key\"}\r\n\r\n")
                             .arg(GetCseq()).toUtf8();
        CseqSelfIncrease();
        tcpSocket->write(Broadcastarray);
    }
    static bool flag = true;
    if(flag)
    {
        flag = !flag;
        QList<QByteArray> PlayList;
        PlayList << QString("{\"command\":\"one_key\",\"cseq\":\"%1\",\"index\":\"/xmedia/onekey/alarm.mp3\"}\r\n\r\n")
                        .arg(GetCseq()).toUtf8();
        CseqSelfIncrease();
        tcpSocket->write(PlayList[0]);
    }
    else
    {
        flag = !flag;
        QList<QByteArray> PlayList;
        PlayList << QString("{\"command\":\"model_change\",\"cseq\":\"%1\",\"model\":\"idle\"}\r\n\r\n").arg(GetCseq()).toUtf8();
        CseqSelfIncrease();
        tcpSocket->write(PlayList[0]);
    }

}

void Acousticcontrol::hander_getUploadFilePath(QString filePath)
{
    UploadFilePath = filePath;
    qDebug() <<"UploadFilePath:"<<UploadFilePath;

}
void Acousticcontrol::UploadFileClicked()
{
    QList<QByteArray> UploadDataList;
    qint64 filesize;
    qDebug() <<"IP:"<<ipv4<<"UploadFile:"<<UploadFilePath;
    UploadFile.setFileName(UploadFilePath);
    UploadFile.open(QIODevice::ReadOnly);
    filesize = UploadFile.size();
    qDebug() <<"UploadFile size:"<< filesize;
    QByteArray array;
    array.resize(tcpSocket->bytesAvailable());
    array =UploadFile.readAll();
    UploadDataList << QString("{\"command\":\"mp3_stream_play\",\"cseq\":\"%1\",\"mp3_len\":\"%2\"}\r\n\r\n")
                          .arg(GetCseq()).arg(filesize).toUtf8();
    UploadDataList << array;
    CseqSelfIncrease();
    if(tcpSocket->isWritable())
    {
        for (int i = 0; i < UploadDataList.size(); ++i) {
            tcpSocket->write(UploadDataList[i]);
        }
    }
}
void Acousticcontrol::btnBroadcastPressed()
{
    if(CurrentPlayMode != PALY_MODE_MIC_BROADCAST)
    {
        CurrentPlayMode = PALY_MODE_MIC_BROADCAST;
        QByteArray Broadcastarray;
        Broadcastarray = QString("{\"command\":\"model_change\",\"cseq\":\"%1\",\"model\":\"mic_broadcast\"}\r\n\r\n")
                             .arg(GetCseq()).toUtf8();
        CseqSelfIncrease();
        tcpSocket->write(Broadcastarray);
    }
}
