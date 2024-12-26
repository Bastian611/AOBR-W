#include "inc/jsondata.h"
#include <QDebug>
JsonData::JsonData()
{

}
/*在一个json对象中插入数据
 * Qjsonobject中按照键值排序，所以与输入输入的顺序不同，实际为ASCII码A-Z顺序由前向后排序
*/
void JsonData::ObjectInsertData(QJsonObject *JsonObject,QString Item,QJsonValue value)
{
    if(JsonObject == nullptr)
    {
        qDebug() << "empty JsonObject ptr";
        return;
    }
    JsonObject->insert(Item,value);

}
/*在json数组中插入一个数据
*/
void JsonData::ArrayInsertData(QJsonArray *JsonArray,QJsonValue value)
{
    if(JsonArray == nullptr)
    {
        qDebug() << "empty JsonArray ptr";
        return;
    }
    JsonArray->append(value);
}
void JsonData::ArrayInsertData(QJsonArray *JsonArray,int index,QJsonValue value)
{
    if(JsonArray == nullptr)
    {
        qDebug() << "empty JsonArray ptr";
        return;
    }
    if(index > JsonArray->size())
    {
        qDebug() << "index error";
        return;
    }

    JsonArray->insert(index,value);
}
void JsonData::ArrayRemoveFirstData(QJsonArray *JsonArray)
{
    if(JsonArray == nullptr)
    {
        qDebug() << "empty JsonArray ptr";
        return;
    }
    JsonArray->removeFirst();
}
void JsonData::ArrayRemoveAtData(QJsonArray* JsonArray,int index)
{
    if(JsonArray == nullptr)
    {
        qDebug() << "empty JsonArray ptr";
        return;
    }
    JsonArray->removeAt(index);
}
void JsonData::ArrayRemoveLastData(QJsonArray *JsonArray)
{
    if(JsonArray == nullptr)
    {
        qDebug() << "empty JsonArray ptr";
        return;
    }
    JsonArray->removeLast();
}
void JsonData::ArrayModifyData(QJsonArray*JsonArray,int index,QJsonValue jsonvalue)
{
    if(JsonArray == nullptr)
    {
        qDebug() << "empty JsonArray ptr";
        return;
    }
    JsonArray->replace(index,jsonvalue);
}
/*在json对象中插入一个json数组
*/
void JsonData::ObjectInsertArray(QJsonObject *JsonObject,QString Item,QJsonArray *JsonArray)
{
    if((JsonObject == nullptr)||(JsonArray == nullptr))
    {
        qDebug() << "empty JsonObject or JsonArray ptr";
        return;
    }
    JsonObject->insert(Item,*JsonArray);
}
/*在json对象中插入一个json对象
*/
void JsonData::ObjectInsertSubObject(QJsonObject*JsonObject,QString Item,QJsonObject*subJsonObject)
{
    if((JsonObject == nullptr)||(subJsonObject == nullptr))
    {
        qDebug() << "empty JsonObject or subJsonObject ptr";
        return;
    }
    JsonObject->insert(Item,*subJsonObject);
}

QString JsonData::GetObjectValueQString(QJsonObject *JsonObject,QString Item)
{
    //Q_UNUSED(unuse);
    QStringList keys = JsonObject->keys();
    for(int i = 0; i<keys.size();i++)
    {
        QString key = keys.at(i);
        if(operator!=(key,Item))
        {
            continue;
        }
        QJsonValue value = JsonObject->value(key);
        if(value.isString())
        {
            return value.toString();
        }
        else
        {
            qDebug()<< Item<<":value is not QString.";
        }
    }
    qDebug()<<"can't find this Item:"<<Item;
    return QString();
}
int JsonData::GetObjectValueInt(QJsonObject*JsonObject,QString Item)
{
    //Q_UNUSED(unuse);
    QStringList keys = JsonObject->keys();
    for(int i = 0; i<keys.size();i++)
    {
        QString key = keys.at(i);
        if(operator!=(key,Item))
        {
            continue;
        }
        QJsonValue value = JsonObject->value(key);
        if(value.isDouble())
        {
            return value.toInt();
        }
        else
        {
            qDebug()<< Item<<":value is not int.";
        }
    }
    qDebug()<<"can't find this Item:"<<Item;
    return 0;
}
bool JsonData::GetObjectValueBool(QJsonObject*JsonObject,QString Item)
{
    //Q_UNUSED(unuse);
    QStringList keys = JsonObject->keys();
    for(int i = 0; i<keys.size();i++)
    {
        QString key = keys.at(i);
        if(operator!=(key,Item))
        {
            continue;
        }
        QJsonValue value = JsonObject->value(key);
        if(value.isBool())
        {
            return value.toBool();
        }
        else
        {
            qDebug()<< Item<<":value is not bool.";
        }
    }
    qDebug()<<"can't find this Item:"<<Item;
    return false;
}
QJsonObject JsonData::GetArrayValueQJsonObject(QJsonArray *JsonArray,int index)
{
    //Q_UNUSED(unuse)
    if(JsonArray == nullptr)
    {
        qDebug() << "empty JsonArray ptr";
        return QJsonObject();
    }
    QJsonObject value;
    QJsonValue jsonvalue;
    jsonvalue = JsonArray->at(index);
    if(jsonvalue.isObject())
    {
        value = jsonvalue.toObject();
        return value;
    }
    return QJsonObject();
}
QString JsonData::GetArrayValueQString(QJsonArray *JsonArray,int index)
{
    //Q_UNUSED(unuse)
    if(JsonArray == nullptr)
    {
        qDebug() << "empty JsonArray ptr";
        return QString();
    }
    QString value;
    QJsonValue jsonvalue;
    jsonvalue = JsonArray->at(index);
    if(jsonvalue.isString())
    {
        value = jsonvalue.toString();
        return value;
    }
    return QString();
}
int JsonData::GetArrayValueInt(QJsonArray *JsonArray,int index)
{
    //Q_UNUSED(unuse)
    if(JsonArray == nullptr)
    {
        qDebug() << "empty JsonArray ptr";
        return 0;
    }
    int value;
    QJsonValue jsonvalue;
    jsonvalue = JsonArray->at(index);
    if(jsonvalue.isDouble())
    {
        value = jsonvalue.toInt();
        return value;
    }
    return 0;
}
bool JsonData::GetArrayValueBool(QJsonArray *JsonArray,int index)
{
    //Q_UNUSED(unuse)
    if(JsonArray == nullptr)
    {
        qDebug() << "empty JsonArray ptr";
        return false;
    }
    bool value;
    QJsonValue jsonvalue;
    jsonvalue = JsonArray->at(index);
    if(jsonvalue.isBool())
    {
        value = jsonvalue.toBool();
        return value;
    }
    return false;
}
void JsonData::ObjectRemoveData(QJsonObject*JsonObject,QString Item)
{
    if(JsonObject == nullptr)
    {
        qDebug() << "ObjectRemoveData's JsonObject is nullptr";
        return ;
    }
    JsonObject->remove(Item);

}
void JsonData::ObjectModifyData(QJsonObject *JsonObject,QString Item,QJsonValue jsonvalue)
{
    if(JsonObject == nullptr)
    {
        qDebug() << "empty JsonObject ptr";
        return;
    }
    JsonObject->insert(Item,jsonvalue);//可替换原有的数据
}
QJsonObject JsonData::getSubObject(QJsonObject* JsonObject,QString Item)
{
    QJsonObject tempJsonObject = *JsonObject;
    QStringList keys = tempJsonObject.keys();
    for(int i = 0; i<keys.size();i++)
    {
        QString key = keys.at(i);
        if(operator!=(key,Item))
        {
            continue;
        }
        QJsonValue value = tempJsonObject.value(key);
        if(value.isObject())
        {
            return value.toObject();
        }
    }
    qDebug()<<"JsonObject no this item" << Item;
    tempJsonObject = QJsonObject();
    return tempJsonObject;
}
QJsonArray JsonData::getSubArray(QJsonObject* JsonObject,QString Item)
{
    QJsonObject tempJsonObject = *JsonObject;
    QJsonArray tempJsonArray;
    QStringList keys = tempJsonObject.keys();
    for(int i = 0; i<keys.size();i++)
    {
        QString key = keys.at(i);
        if(operator!=(key,Item))
        {
            continue;
        }
        QJsonValue value = tempJsonObject.value(key);
        if(value.isArray())
        {
            tempJsonArray = value.toArray();
            return tempJsonArray;
        }
    }
    tempJsonArray = QJsonArray();
    return tempJsonArray;
}
QString JsonData::getSubObjectValueQString(QJsonObject*JsonObject,QString Item,QString SubItem)
{
    //Q_UNUSED(unuse);
    QStringList keys = JsonObject->keys();
    QJsonObject tempsubJsonObject;
    QStringList subKeys;
    QJsonValue subValue;
    for(int i = 0; i<keys.size();i++)
    {
        QString key = keys.at(i);
        if(operator!=(key,Item))
        {
            continue;
        }
        QJsonValue value = JsonObject->value(key);
        if(value.isObject())
        {
            tempsubJsonObject = value.toObject();
            subKeys = tempsubJsonObject.keys();
            for (int k = 0; k < subKeys.size(); ++k)
            {
                QString subkey = subKeys.at(k);
                if(operator!=(subkey,SubItem))
                {
                    continue;
                }
                subValue = tempsubJsonObject.value(subkey);
                if(subValue.isString())
                {
                    return subValue.toString();
                }
            }
        }
        else
        {
            qDebug()<< Item<<":value is not subJsonObject.";
        }
    }
    qDebug()<<"can't find this Item:"<<Item;
    return QString();
}
int JsonData::getSubObjectValueInt(QJsonObject*JsonObject,QString Item,QString SubItem)
{
    //Q_UNUSED(unuse);
    QStringList keys = JsonObject->keys();
    QJsonObject tempsubJsonObject;
    QStringList subKeys;
    QJsonValue subValue;
    for(int i = 0; i<keys.size();i++)
    {
        QString key = keys.at(i);
        if(operator!=(key,Item))
        {
            continue;
        }
        QJsonValue value = JsonObject->value(key);
        if(value.isObject())
        {
            tempsubJsonObject = value.toObject();
            subKeys = tempsubJsonObject.keys();
            for (int k = 0; k < subKeys.size(); ++k)
            {
                QString subkey = subKeys.at(k);
                if(operator!=(subkey,SubItem))
                {
                    continue;
                }
                subValue = tempsubJsonObject.value(subkey);
                if(subValue.isDouble())
                {
                    return subValue.toInt();
                }
            }
        }
        else
        {
            qDebug()<< Item<<":value is not subJsonObject.";
        }
    }
    qDebug()<<"can't find this Item:"<<Item;
    return 0;
}
bool JsonData::getSubObjectValueBool(QJsonObject*JsonObject,QString Item,QString SubItem)
{
    //Q_UNUSED(unuse);
    QStringList keys = JsonObject->keys();
    QJsonObject tempsubJsonObject;
    QStringList subKeys;
    QJsonValue subValue;
    for(int i = 0; i<keys.size();i++)
    {
        QString key = keys.at(i);
        if(operator!=(key,Item))
        {
            continue;
        }
        QJsonValue value = JsonObject->value(key);
        if(value.isObject())
        {
            tempsubJsonObject = value.toObject();
            subKeys = tempsubJsonObject.keys();
            for (int k = 0; k < subKeys.size(); ++k)
            {
                QString subkey = subKeys.at(k);
                if(operator!=(subkey,SubItem))
                {
                    continue;
                }
                subValue = tempsubJsonObject.value(subkey);
                if(subValue.isBool())
                {
                    return subValue.toBool();
                }
            }
        }
        else
        {
            qDebug()<< Item<<":value is not subJsonObject.";
        }
    }
    qDebug()<<"can't find this Item:"<<Item;
    return false;
}
void JsonData::ObjectWriteToFile(QJsonObject *JsonObject,QString filePath)
{
    QJsonDocument doc(*JsonObject);
    QByteArray json = doc.toJson();//json数据转换文本字符串
    QFile file(filePath);
    if(file.open(QFile::WriteOnly))
    {
        if(!file.isWritable())
        {
            file.waitForBytesWritten(2);
        }
        file.write(json);
    }
    file.close();
}
void JsonData::ObjectReadFromFile(QJsonObject*JsonObject,QString filePath)
{
    QFile file(filePath);
    if(file.open(QFile::ReadOnly))
    {
        QByteArray all = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(all);
        if(doc.isObject())
        {
            *JsonObject = doc.object();
        }
        file.close();
    }
}
//将object对象转换为字符串
QByteArray JsonData::ObjectToByteArray(QJsonObject *JsonObject)
{
    QByteArray array;
    QJsonDocument doc(*JsonObject);
    array = doc.toJson();//json数据转换文本字符串
    array.replace(" ","");//剔除空格符
    array.replace("\n","");//剔除换行符
    return array;
}

//将字符串转换为object数组
QJsonObject JsonData::ByteArrayToObject(QByteArray array)
{
    QJsonObject JsonObject;
    QJsonDocument doc;
    doc = QJsonDocument::fromJson(array);
    if(doc.isObject())
    {
        JsonObject = doc.object();
    }
    return JsonObject;
}
QJsonObject JsonData::ByteArrayToObject(QByteArray array,const char *prepend,const char *append)
{
    QJsonObject JsonObject;
    QJsonDocument doc;
    array.prepend(prepend);//头部加‘{’
    array.append(append);//尾部加‘}’
    doc = QJsonDocument::fromJson(array);
    if(doc.isObject())
    {
        JsonObject = doc.object();
    }
    return JsonObject;
}
QByteArray JsonData::ArrayToByteArray(QJsonArray* jsonarray,QString arrayName)
{
    QByteArray array;
    QJsonObject JsonObject;
    QString ptr(arrayName);
    JsonObject.insert(ptr,*jsonarray);
    QJsonDocument doc(JsonObject);
    array = doc.toJson();//json数据转换文本字符串
    array.replace(" ","");//剔除空格符
    array.replace("\n","");//剔除换行符
    array.remove(0,1);//掐头
    array.chop(1);//去尾
    return array;
}
QJsonArray JsonData::ByteArrayToArray(QByteArray array,QString *Item)
{
    QJsonArray jsonarray;
    QJsonObject JsonObject;
    QByteArray temparray = array;
    //在头和尾加‘{’和‘}’
    temparray.prepend("{");//头部加‘{’
    temparray.append("}");//尾部加‘}’
    //转换为Qobject
    JsonObject = ByteArrayToObject(temparray);
    //转换为QJsonArray
    QString key = JsonObject.keys().at(0);
    QJsonValue value = JsonObject.value(key);
    if(value.isArray())
    {
        jsonarray = value.toArray();
        Item->append(key);
        return jsonarray;
    }
    jsonarray = QJsonArray();
    return jsonarray;
}
//增加自定义末尾标识符
QByteArray JsonData::ByteArrayAppend(QByteArray array)
{
    QByteArray temparray;
    temparray = array;
    temparray.append("\r\n\r\n");
    return temparray;
}
//剔除自定义末尾标识符
QByteArray JsonData::ByteArrayTrimmed(QByteArray array)
{
    QByteArray temparray;
    temparray = array;
    temparray.replace("\r\n\r\n","");
    return temparray;
}
QString  JsonData::QStringTrimmedMid(QString strsrc,QString strarg)
{
    QString tempstrsrc;
    tempstrsrc = strsrc;
    int index = strarg.length();
    tempstrsrc = tempstrsrc.mid(index);
    return tempstrsrc;
}
