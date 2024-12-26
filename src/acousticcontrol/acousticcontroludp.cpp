#include "inc/acousticcontroludp.h"
#include <QDebug>
AcousticcontrolUDP::AcousticcontrolUDP(QObject *parent) : QObject(parent)
{
    qDebug() << "AcousticcontrolUDP init.";
    /*****/
    jsondata = new JsonData();
    start();
    audioInInit();
    //audioInTest();
}
void AcousticcontrolUDP::start()
{
    IPInit();
    connect(this,&AcousticcontrolUDP::startSignal,this,&AcousticcontrolUDP::Init);
    qDebug() << "AcousticcontrolUDP start";

}
void AcousticcontrolUDP::Init()
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::AnyIPv4,9000);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(readData()));
}

void AcousticcontrolUDP::readData()
{
    QByteArray array;
    QHostAddress address;
    quint16 port;
    array.resize(udpSocket->bytesAvailable());
    udpSocket->readDatagram(array.data(),array.size(),&address,&port);//获取ip地址和端口
    qDebug() << array << address<< port;
}
void AcousticcontrolUDP::sendData()
{
    qDebug() << "send data";
    udpSocket->writeDatagram("hello",QHostAddress("192.168.1.200"),8999);
}
void AcousticcontrolUDP::IPInit()
{
    ipv4 = "";
    port = 0;
    //jsondata = new JsonData();
    QJsonObject tempjsonobject,tempsubjsonobject;
    QFile file("./IP.json");
    if(file.exists())
    {
        jsondata->ObjectReadFromFile(&tempjsonobject,"./IP.json");
        tempsubjsonobject = jsondata->getSubObject(&tempjsonobject,"AcousticcontrolUDP");
        ipv4 = jsondata->GetObjectValueQString(&tempsubjsonobject,"ip");
        port = jsondata->GetObjectValueQString(&tempsubjsonobject,"port").toUShort();
        if(ipv4.isEmpty())
        {
            tempsubjsonobject = QJsonObject();
            ipv4 = "192.168.1.200";
            port = 8999;
            jsondata->ObjectInsertData(&tempsubjsonobject,"ip",ipv4);
            jsondata->ObjectInsertData(&tempsubjsonobject,"port",QString("%1").arg(port));
            jsondata->ObjectInsertSubObject(&tempjsonobject,"AcousticcontrolUDP",&tempsubjsonobject);
            jsondata->ObjectWriteToFile(&tempjsonobject,"./IP.json");
        }
    }
    else
    {
        ipv4 = "192.168.1.200";
        port = 8999;
        jsondata->ObjectInsertData(&tempsubjsonobject,"ip",ipv4);
        jsondata->ObjectInsertData(&tempsubjsonobject,"port",QString("%1").arg(port));
        jsondata->ObjectInsertSubObject(&tempjsonobject,"AcousticcontrolUDP",&tempsubjsonobject);
        jsondata->ObjectWriteToFile(&tempjsonobject,"./IP.json");
    }
    QTimer::singleShot (100,this,SLOT(TimeoutSetIP()));//避免在信号与槽建立成功前发送了无效信号，故延时100ms后单次触发
}
void AcousticcontrolUDP::TimeoutSetIP()
{
    emit sig_ConnectState(DEVICE_NAME_ACOUSTICCONTROL_UDP,ipv4,QString("%1").arg(port),QAbstractSocket::UnconnectedState);
}
void AcousticcontrolUDP::audioInInit()
{
    QAudioFormat AduioInFormat;
    AduioInFormat.setSampleRate(16000);
    AduioInFormat.setChannelCount(1);
    AduioInFormat.setSampleSize(16);
    AduioInFormat.setCodec("audio/pcm");
    AduioInFormat.setByteOrder(QAudioFormat::LittleEndian);
    AduioInFormat.setSampleType(QAudioFormat::SignedInt);
    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
    if (!info.isFormatSupported(AduioInFormat)) {
        qWarning() << "Default format not supported, trying to use the nearest.";
        AduioInFormat = info.nearestFormat(AduioInFormat);
    }
    audioIn = new QAudioInput(AduioInFormat, this);
    connect(audioIn, SIGNAL(stateChanged(QAudio::State)), this, SLOT(AudioInStreamStatus(QAudio::State)));
}
//一键喊话模式，需先切换至一键喊话模式
void AcousticcontrolUDP::btnBroadcastClicked()
{
    static bool flag = true;
    if(flag)
    {
        flag = !flag;
        qDebug() <<"start Broadcast";
        audio_InStream = audioIn->start();
        connect(audio_InStream,SIGNAL(readyRead()),this,SLOT(AudioInStreamReadyRead()),Qt::QueuedConnection);
    }
    else
    {
        flag = !flag;
        qDebug() <<"stop Broadcast";
        audioIn->stop();
    }
}
void AcousticcontrolUDP::audioInTest()
{
    destinationFile.setFileName("Z:/workspace/qtProject/AOBR_Server/TestAudio/4.pcm");
    destinationFile.open(QIODevice::WriteOnly | QIODevice::Truncate );
    QAudioFormat format;
    // Set up the desired format, for example:
    format.setSampleRate(48000);
    format.setChannelCount(1);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
    if (!info.isFormatSupported(format)) {
        qWarning() << "Default format not supported, trying to use the nearest.";
        format = info.nearestFormat(format);
    }

    audioIn = new QAudioInput(format, this);
    connect(audioIn, SIGNAL(stateChanged(QAudio::State)), this, SLOT(AudioInStreamStatus(QAudio::State)));

    QTimer::singleShot(10000, this, SLOT(stopRecording()));
    audioIn->start(&destinationFile);
    // Records audio for 10000ms
}
void AcousticcontrolUDP::stopRecording()
{
    audioIn->stop();
    destinationFile.close();
    delete audioIn;
}

//有音频信号可以读
void AcousticcontrolUDP::AudioInStreamReadyRead()
{
    //读到数据即发送
    QByteArray AudioInStream;
    AudioInStream.resize(udpSocket->bytesAvailable());
    AudioInStream = audio_InStream->readAll();
    udpSocket->writeDatagram(AudioInStream,QHostAddress("192.168.1.200"),8999);
}
//录音状态
void AcousticcontrolUDP::AudioInStreamStatus(QAudio::State newState)
{
    switch (newState) {
    case QAudio::StoppedState:
        if(audioIn->error() != QAudio::NoError)
        {
            qDebug()<<"从麦克风读取数据出现错误.\n";
        }
        else
        {
            qDebug()<<"关闭麦克风.\n";
        }
        break;
    case QAudio::ActiveState:
        qDebug()<<"开始从麦克风设备实时读取PCM声音数据.\n";
        break;
    default:
        break;
    }
}
//麦克风音量控制
void AcousticcontrolUDP::SliderCapVolumeChanged(int value)
{
    static float volume = 0.5;
    volume = value * 0.01;
    audioIn->setVolume(volume);
}
void AcousticcontrolUDP::handle_IPSet(QString ip,QString Port)
{
    QJsonObject tempjsonobject,tempsubjsonobject;
    QFile file("./IP.json");
    if(file.exists())
    {
        jsondata->ObjectReadFromFile(&tempjsonobject,"./IP.json");
        jsondata->ObjectInsertData(&tempsubjsonobject,"ip",ip);
        jsondata->ObjectInsertData(&tempsubjsonobject,"port",Port);
        jsondata->ObjectInsertSubObject(&tempjsonobject,"AcousticcontrolUDP",&tempsubjsonobject);
        jsondata->ObjectWriteToFile(&tempjsonobject,"./IP.json");
        ipv4 = ip;
        port = Port.toUShort();
        emit sig_ConnectState(DEVICE_NAME_ACOUSTICCONTROL_UDP,ipv4,QString("%1").arg(port),QAbstractSocket::UnconnectedState);
        return ;
    }
    else {
        jsondata->ObjectInsertData(&tempsubjsonobject,"ip",ip);
        jsondata->ObjectInsertData(&tempsubjsonobject,"port",Port);
        jsondata->ObjectInsertSubObject(&tempjsonobject,"AcousticcontrolUDP",&tempsubjsonobject);
        jsondata->ObjectWriteToFile(&tempjsonobject,"./IP.json");
        ipv4 = ip;
        port = Port.toUShort();
        emit sig_ConnectState(DEVICE_NAME_ACOUSTICCONTROL_UDP,ipv4,QString("%1").arg(port),QAbstractSocket::UnconnectedState);
        return ;
    }
}
