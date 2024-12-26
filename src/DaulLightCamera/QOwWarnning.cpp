#include "inc/QOwWarnning.h"
#include "ui_QOwWarnning.h"

QOwWarnning::QOwWarnning(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QOwWarnning)
{
    ui->setupUi(this);
    qDebug() << "start OwWarnning";

    // 设置定时器，每秒触发一次
    // m_timer = new QTimer;
    // m_timer->start(1000);

    // 设置网络请求完成后的回调
    // m_networkManager = new QNetworkAccessManager;
    m_timerLight = new QTimer;
    m_webSocket = new QWebSocket;
    m_listWidget = new QListWidget;

    IPInit();
    // m_Url = "http://192.168.1.106:80/自定义路径"; // http模式的url
    // m_Url = "ws://192.168.1.16:9801/subscribe"; // ws模式的url

    // 连接信号与槽
    // connect(m_timer,            &QTimer::timeout,                   this,   &QOwWarnning::onTimeout);
    // connect(m_networkManager,   &QNetworkAccessManager::finished,   this,   &QOwWarnning::onHttpRequestFinished);
    connect(m_timerLight,       &QTimer::timeout,                   this,   &QOwWarnning::onPointChange);
    connect(m_webSocket,        &QWebSocket::connected,             this,   &QOwWarnning::onConnected);
    connect(m_webSocket,        &QWebSocket::binaryMessageReceived, this,   &QOwWarnning::onBinaryMessageReceived);
    connect(m_webSocket,        &QWebSocket::stateChanged,          this,   &QOwWarnning::onStateChanged);
    connect(m_webSocket,        &QWebSocket::disconnected,          this,   &QOwWarnning::onDisconnected);

    m_webSocket->open(QUrl(m_Url));

    ui->lbWarnPoint->setPixmap(QPixmap(":/photo/yellow.png"));
    ui->lbWarnTip->setVisible(false);
}

QOwWarnning::~QOwWarnning()
{
    delete m_listWidget;
    // delete m_networkManager;
    // m_timer->stop();
    m_timerLight->stop();
    // delete m_timer;
    delete m_timerLight;
    m_webSocket->close();
    delete m_webSocket;
    delete ui;
}

void QOwWarnning::onTimeout()
{
    updateData();  // 每次定时触发时请求数据
    // static_parser_test();
}

void QOwWarnning::onConnected()
{
    qDebug() << "WebSocket connected!";
}

void QOwWarnning::onStateChanged(QAbstractSocket::SocketState state)
{
    qDebug() << "WebSocket State: " << state;
}

void QOwWarnning::onDisconnected()
{
    qDebug() << "WebSocket Disconnected!";
}

void QOwWarnning::onBinaryMessageReceived(const QByteArray &msgArray)
{
    qDebug() << "Received message from server:" /*<< message*/;
    // 处理JSON消息
    QJsonDocument doc = QJsonDocument::fromJson(msgArray);
    parserData(doc);
    // parserDataStr(message);
}

void QOwWarnning::updateData()
{
    QUrl url(m_Url);
    QNetworkRequest request(url);
    // m_networkManager->get(request); // 发送GET请求
}

void QOwWarnning::onHttpRequestFinished(QNetworkReply* reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        qWarning() << "HTTP request failed:" << reply->errorString();
        reply->deleteLater();
        return;
    }

    // 解析返回的JSON数据
    QByteArray responseData = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(responseData);
    if (doc.isNull()) {
        qWarning() << "Failed to parse JSON data.";
        reply->deleteLater();
        return;
    }

    parserData(doc);
    reply->deleteLater();
}

void QOwWarnning::parserData(const QJsonDocument& doc)
{
    QJsonObject rootObj = doc.object();

    if (rootObj.contains("Data") && rootObj["Data"].isObject())
    {
        // 用于显示文字和图片
        QListWidgetItem* item = new QListWidgetItem();
        QWidget *widget = new QWidget();
        QVBoxLayout *itemLayout = new QVBoxLayout(widget);
        int imgWidth, imgHeight;

        QJsonObject datObj = rootObj["Data"].toObject();

        // 提取时间信息
        if (datObj.contains("time") && datObj["time"].isString())
        {
            QString time = datObj["time"].toString();
            QLabel* lbTime = new QLabel("抓拍时间： " + time);
            itemLayout->addWidget(lbTime);
        }

        // 提取告警通道id
        if (datObj.contains("chId") && datObj["chId"].isString())
        {
            QString chId = datObj["chId"].toString();
            // qDebug() << "chId: " << chId;
        }

        // 提取pluginId
        if (datObj.contains("pluginId") && datObj["pluginId"].isDouble())
        {
            int pluginId = datObj["pluginId"].toInt();
            // qDebug() << "pluginId: " << pluginId;
        }

        // 提取pluginName
        if (datObj.contains("pluginName") && datObj["pluginName"].isString())
        {
            QString pluginName = datObj["pluginName"].toString();
            // qDebug() << "pluginName: " << pluginName;
        }

        // 提取seq
        if (datObj.contains("seq") && datObj["seq"].isDouble())
        {
            int seq = datObj["seq"].toInt();
            // qDebug() << "seq: " << seq;
        }

        // 提取errorCode
        if (datObj.contains("errorCode") && datObj["errorCode"].isDouble())
        {
            int code = datObj["errorCode"].toInt();
            // qDebug() << "errorCode: " << code;
        }

        // 提取errorMsg
        if (datObj.contains("errorMsg") && datObj["errorMsg"].isString())
        {
            QString msg = datObj["errorMsg"].toString();
            // qDebug() << "errorMsg: " << msg;
        }

        // 提取result信息
        if (datObj.contains("result") && datObj["result"].isObject())
        {
            QJsonObject retObj = datObj["result"].toObject();

            // 提取目标数量
            if (retObj.contains("ObjectNum") && retObj["ObjectNum"].isDouble())
            {
                int tarNum = retObj["ObjectNum"].toInt();
                QLabel* lbNum = new QLabel(QString("目标数量： %1").arg(tarNum));
                itemLayout->addWidget(lbNum);
            }

            // 提取目标信息
            if (retObj.contains("Objects") && retObj["Objects"].isArray())
            {
                QJsonArray objArray = retObj["Objects"].toArray();

                for (const QJsonValue& value: objArray)
                {
                    QJsonObject itemObj = value.toObject();

                    // 提取告警模块ID
                    int moduleId = itemObj.value("moduleId").toInt();
                    // qDebug() << "moduleId:" << moduleId;

                    // 提取告警模块名称
                    QString model = itemObj.value("moduleName").toString();
                    QLabel* lbModel = new QLabel("告警模块： " + model);
                    itemLayout->addWidget(lbModel);

                    // 提取置信度
                    float prob = itemObj.value("prob").toDouble();
                    // qDebug() << "prob:" << prob;

                    // 提取位置X
                    int posX = itemObj.value("X").toInt();
                    // qDebug() << "posX:" << posX;

                    // 提取位置Y
                    int posY = itemObj.value("Y").toInt();
                    // qDebug() << "posY:" << posY;

                    // 提取目标宽度
                    int tarWidth = itemObj.value("Width").toInt();
                    // qDebug() << "tarWidth:" << tarWidth;

                    // 提取目标高度
                    int tarHeight = itemObj.value("Height").toInt();
                    // qDebug() << "tarHeight:" << tarHeight;
                }
                // 增加事件地点
                QLabel* lbPos = new QLabel("事件地点： 机场围界");
                itemLayout->addWidget(lbPos);
            }

            // 提取图片宽度
            if (retObj.contains("ImageWidth") && retObj["ImageWidth"].isDouble())
            {
                imgWidth = retObj["ImageWidth"].toInt();
            }

            // 提取图片高度
            if (retObj.contains("ImageHeight") && retObj["ImageHeight"].isDouble())
            {
                imgHeight = retObj["ImageHeight"].toInt();
            }

            // 提取图片
            if (retObj.contains("ImageData") && retObj["ImageData"].isString())
            {
                QString rawImg = retObj["ImageData"].toString();
                QPixmap pixmap;
                if (!rawImg.isEmpty())
                {
                    QByteArray img = QByteArray::fromBase64(rawImg.toUtf8());
                    pixmap.loadFromData(img);
                    pixmap = pixmap.scaled(QSize(280, imgHeight*350/imgWidth), Qt::KeepAspectRatio);
                }
                if (!pixmap.isNull())
                {
                    QLabel* lbImg = new QLabel();
                    lbImg->setPixmap(pixmap);
                    itemLayout->addWidget(lbImg);
                }
            }
        }

        QLabel* lbLine = new QLabel();
        lbLine->setText("------------------------------------------------------------");
        itemLayout->addWidget(lbLine);

        widget->setLayout(itemLayout);
        item->setSizeHint(widget->sizeHint());

        // m_listWidget->addItem(item);
        m_listWidget->insertItem(0, item);
        m_listWidget->setItemWidget(item, widget);
        ui->vblWarnEvent->addWidget(m_listWidget);

        ui->lbWarnPoint->setPixmap(QPixmap(":/photo/red.png"));
        ui->lbWarnTip->setVisible(true);
        m_timerLight->start(120000);
    } else {
        QMessageBox::warning(this, "Data Error", "The returned JSON does not contain valid data.");
    }
}

void QOwWarnning::parserDataStr(const QString& jsonStr)
{
    QJsonDocument doc = QJsonDocument::fromJson(jsonStr.toUtf8());
    parserData(doc);
}

void QOwWarnning::static_parser_test()
{
    QFile file("./test1.json");

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "无法打开文件";
        return ;
    }

    // 读取文件内容到一个字符串
    QByteArray jsonData = file.readAll();

    // 创建一个 QJsonDocument 对象
    QJsonDocument document = QJsonDocument::fromJson(jsonData);

    // 确认文档不为空并且是对象
    if (!document.isNull() && document.isObject()) {
        parserData(document);
    } else {
        qDebug() << "无效的 JSON 文档";
    }

}

void QOwWarnning::onPointChange()
{
    ui->lbWarnPoint->setPixmap(QPixmap(":/photo/green.png"));
    ui->lbWarnTip->setVisible(false);
}

void QOwWarnning::IPInit()
{
    qDebug()<<"OwWarnning init";
    JsonData* jsondata = new JsonData();
    QJsonObject tempjsonobject,tempsubjsonobject;
    QFile file("./IP.json");
    tempjsonobject = QJsonObject();
    tempsubjsonobject = QJsonObject();
    if(file.exists())
    {
        jsondata->ObjectReadFromFile(&tempjsonobject, "./IP.json");
        tempsubjsonobject = jsondata->getSubObject(&tempjsonobject, "OwWarnning");
        m_Url = jsondata->GetObjectValueQString(&tempsubjsonobject, "url");
        if(m_Url.isEmpty())
        {
            tempjsonobject = QJsonObject();
            m_Url = "ws://192.168.1.16:9801/subscribe";
            jsondata->ObjectInsertData(&tempsubjsonobject, "url", m_Url);
            jsondata->ObjectInsertSubObject(&tempjsonobject, "OwWarnning", &tempsubjsonobject);
            jsondata->ObjectWriteToFile(&tempjsonobject, "./IP.json");
        }
    }
    else{
        m_Url = "ws://192.168.1.16:9801/subscribe";
        jsondata->ObjectInsertData(&tempsubjsonobject, "url", m_Url);
        jsondata->ObjectInsertSubObject(&tempjsonobject, "OwWarnning", &tempsubjsonobject);
        jsondata->ObjectWriteToFile(&tempjsonobject, "./IP.json");
    }
}
