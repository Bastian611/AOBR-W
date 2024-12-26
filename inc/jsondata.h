#ifndef JsonData_H
#define JsonData_H

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonDocument>
#include <QFile>

// Json类
class JsonData
{
public:
    JsonData();
    void ObjectInsertData(QJsonObject*,QString,QJsonValue);//增
    void ObjectInsertArray(QJsonObject*,QString,QJsonArray*);
    void ObjectInsertSubObject(QJsonObject*,QString,QJsonObject*);
    void ObjectRemoveData(QJsonObject*,QString);//删
    void ObjectModifyData(QJsonObject*,QString,QJsonValue);
    void ArrayInsertData(QJsonArray*,QJsonValue);
    void ArrayInsertData(QJsonArray*,int,QJsonValue);
    void ArrayRemoveFirstData(QJsonArray*);
    void ArrayRemoveLastData(QJsonArray*);
    void ArrayRemoveAtData(QJsonArray*,int index);
    void ArrayModifyData(QJsonArray*,int index,QJsonValue);
    QString GetObjectValueQString(QJsonObject*,QString);//获取
    int     GetObjectValueInt(QJsonObject*,QString);
    bool    GetObjectValueBool(QJsonObject*,QString);
    QJsonObject GetArrayValueQJsonObject(QJsonArray *JsonArray,int index);
    QString GetArrayValueQString(QJsonArray*,int index);
    int     GetArrayValueInt(QJsonArray*,int index);
    bool    GetArrayValueBool(QJsonArray*,int index);
    QJsonObject getSubObject(QJsonObject*,QString);
    QJsonArray  getSubArray(QJsonObject*,QString);
    //SubObject value get
    QString getSubObjectValueQString(QJsonObject*,QString,QString);//子对象的字符串值成员
    int     getSubObjectValueInt(QJsonObject*,QString,QString);//子对象的int值成员
    bool    getSubObjectValueBool(QJsonObject*,QString,QString);//子对象的bool值成员
    void    ObjectWriteToFile(QJsonObject*,QString filePath);//写入json文件
    void    ObjectReadFromFile(QJsonObject*,QString filePath);//读取json文件
    QByteArray  ObjectToByteArray(QJsonObject*);//json对象转换字符串数组
    QJsonObject ByteArrayToObject(QByteArray);//字符串数组转换json对象
    QJsonObject ByteArrayToObject(QByteArray,const char * prepend,const char * append);//不带{}的字符串处理
    QByteArray  ArrayToByteArray(QJsonArray*,QString);
    QJsonArray  ByteArrayToArray(QByteArray,QString *);
    QByteArray  ByteArrayAppend(QByteArray);//增加自定义末尾标识符
    QByteArray  ByteArrayTrimmed(QByteArray);//剔除自定义末尾标识符
    QString     QStringTrimmedMid(QString strsrc,QString strarg);//剔除字符串左侧一段字符串
};

#endif // JsonData_H
