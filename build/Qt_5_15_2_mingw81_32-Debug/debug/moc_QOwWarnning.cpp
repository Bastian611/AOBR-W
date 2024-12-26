/****************************************************************************
** Meta object code from reading C++ file 'QOwWarnning.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../inc/QOwWarnning.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QOwWarnning.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QOwWarnning_t {
    QByteArrayData data[14];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QOwWarnning_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QOwWarnning_t qt_meta_stringdata_QOwWarnning = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QOwWarnning"
QT_MOC_LITERAL(1, 12, 9), // "onTimeout"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 21), // "onHttpRequestFinished"
QT_MOC_LITERAL(4, 45, 14), // "QNetworkReply*"
QT_MOC_LITERAL(5, 60, 5), // "reply"
QT_MOC_LITERAL(6, 66, 13), // "onPointChange"
QT_MOC_LITERAL(7, 80, 11), // "onConnected"
QT_MOC_LITERAL(8, 92, 14), // "onStateChanged"
QT_MOC_LITERAL(9, 107, 28), // "QAbstractSocket::SocketState"
QT_MOC_LITERAL(10, 136, 5), // "state"
QT_MOC_LITERAL(11, 142, 14), // "onDisconnected"
QT_MOC_LITERAL(12, 157, 23), // "onBinaryMessageReceived"
QT_MOC_LITERAL(13, 181, 8) // "msgArray"

    },
    "QOwWarnning\0onTimeout\0\0onHttpRequestFinished\0"
    "QNetworkReply*\0reply\0onPointChange\0"
    "onConnected\0onStateChanged\0"
    "QAbstractSocket::SocketState\0state\0"
    "onDisconnected\0onBinaryMessageReceived\0"
    "msgArray"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QOwWarnning[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    1,   50,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    1,   55,    2, 0x08 /* Private */,
      11,    0,   58,    2, 0x08 /* Private */,
      12,    1,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   13,

       0        // eod
};

void QOwWarnning::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QOwWarnning *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onTimeout(); break;
        case 1: _t->onHttpRequestFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->onPointChange(); break;
        case 3: _t->onConnected(); break;
        case 4: _t->onStateChanged((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 5: _t->onDisconnected(); break;
        case 6: _t->onBinaryMessageReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketState >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QOwWarnning::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QOwWarnning.data,
    qt_meta_data_QOwWarnning,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QOwWarnning::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QOwWarnning::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QOwWarnning.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QOwWarnning::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
