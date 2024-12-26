#ifndef QOWWARNNING_H
#define QOWWARNNING_H

#include <QWidget>
#include <QNetworkReply>
#include <QVBoxLayout>
#include <QListWidget>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QFile>
#include <QWebSocket>
#include "jsondata.h"

namespace Ui {
class QOwWarnning;
}

class QOwWarnning : public QWidget
{
    Q_OBJECT

public:
    explicit QOwWarnning(QWidget *parent = nullptr);
    ~QOwWarnning();

private slots:
    // http接收
    void onTimeout();  // 每秒定时更新
    void onHttpRequestFinished(QNetworkReply* reply);  // HTTP请求完成后的回调
    void onPointChange();

    // webSocket接收
    void onConnected();               // WebSocket连接成功
    void onStateChanged(QAbstractSocket::SocketState state);
    void onDisconnected();
    void onBinaryMessageReceived(const QByteArray &msgArray);  // 接收到文本消息

private:
    void updateData();  // 获取数据并更新界面
    void parserData(const QJsonDocument& doc); // 解析json数据
    void parserDataStr(const QString& jsonStr);
    void static_parser_test(); // 静态测试文件解析
    void IPInit();

private:
    Ui::QOwWarnning*        ui;
    QListWidget*            m_listWidget;       // 用于显示数据的列表
    QNetworkAccessManager*  m_networkManager;   // 网络请求管理器
    QTimer*                 m_timer;            // 定时器，用于定时发送请求
    QString                 m_Url;              // 请求的API地址
    QTimer*                 m_timerLight;       // 定时器，用于警示点计时
    QWebSocket*             m_webSocket;        // WebSocket对象
};

#endif // QOWWARNNING_H
