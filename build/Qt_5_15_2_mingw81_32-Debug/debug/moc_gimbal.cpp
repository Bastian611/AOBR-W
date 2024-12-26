/****************************************************************************
** Meta object code from reading C++ file 'gimbal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../inc/gimbal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gimbal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Gimbal_t {
    QByteArrayData data[33];
    char stringdata0[492];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Gimbal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Gimbal_t qt_meta_stringdata_Gimbal = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Gimbal"
QT_MOC_LITERAL(1, 7, 11), // "startSignal"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 13), // "sendAngleData"
QT_MOC_LITERAL(4, 34, 4), // "type"
QT_MOC_LITERAL(5, 39, 5), // "angle"
QT_MOC_LITERAL(6, 45, 14), // "sendDataSignal"
QT_MOC_LITERAL(7, 60, 5), // "value"
QT_MOC_LITERAL(8, 66, 5), // "state"
QT_MOC_LITERAL(9, 72, 16), // "sig_ConnectState"
QT_MOC_LITERAL(10, 89, 10), // "deviceName"
QT_MOC_LITERAL(11, 100, 2), // "IP"
QT_MOC_LITERAL(12, 103, 4), // "Port"
QT_MOC_LITERAL(13, 108, 11), // "SocketState"
QT_MOC_LITERAL(14, 120, 5), // "start"
QT_MOC_LITERAL(15, 126, 4), // "Init"
QT_MOC_LITERAL(16, 131, 18), // "getAngleHorizontal"
QT_MOC_LITERAL(17, 150, 16), // "getAngleVertical"
QT_MOC_LITERAL(18, 167, 8), // "readData"
QT_MOC_LITERAL(19, 176, 13), // "connectedSlot"
QT_MOC_LITERAL(20, 190, 12), // "sendDataSlot"
QT_MOC_LITERAL(21, 203, 24), // "VspeedSliderValueChanged"
QT_MOC_LITERAL(22, 228, 24), // "HspeedSliderValueChanged"
QT_MOC_LITERAL(23, 253, 29), // "btnRealtimeAckhaulOpenClicked"
QT_MOC_LITERAL(24, 283, 30), // "btnRealtimeAckhaulCloseClicked"
QT_MOC_LITERAL(25, 314, 30), // "comboBox_RealtimeAckhaulChange"
QT_MOC_LITERAL(26, 345, 4), // "arg1"
QT_MOC_LITERAL(27, 350, 18), // "handleDisconnected"
QT_MOC_LITERAL(28, 369, 11), // "handleError"
QT_MOC_LITERAL(29, 381, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(30, 410, 17), // "btnConnectClicked"
QT_MOC_LITERAL(31, 428, 25), // "btnOneClickZeroingClicked"
QT_MOC_LITERAL(32, 454, 37) // "handle_checkBoxRealtimeAckhau..."

    },
    "Gimbal\0startSignal\0\0sendAngleData\0"
    "type\0angle\0sendDataSignal\0value\0state\0"
    "sig_ConnectState\0deviceName\0IP\0Port\0"
    "SocketState\0start\0Init\0getAngleHorizontal\0"
    "getAngleVertical\0readData\0connectedSlot\0"
    "sendDataSlot\0VspeedSliderValueChanged\0"
    "HspeedSliderValueChanged\0"
    "btnRealtimeAckhaulOpenClicked\0"
    "btnRealtimeAckhaulCloseClicked\0"
    "comboBox_RealtimeAckhaulChange\0arg1\0"
    "handleDisconnected\0handleError\0"
    "QAbstractSocket::SocketError\0"
    "btnConnectClicked\0btnOneClickZeroingClicked\0"
    "handle_checkBoxRealtimeAckhaulOpenSet"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Gimbal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  119,    2, 0x06 /* Public */,
       3,    2,  120,    2, 0x06 /* Public */,
       6,    2,  125,    2, 0x06 /* Public */,
       9,    4,  130,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  139,    2, 0x0a /* Public */,
      15,    0,  140,    2, 0x0a /* Public */,
      16,    0,  141,    2, 0x0a /* Public */,
      17,    0,  142,    2, 0x0a /* Public */,
      18,    0,  143,    2, 0x08 /* Private */,
      19,    0,  144,    2, 0x08 /* Private */,
      20,    2,  145,    2, 0x08 /* Private */,
      21,    1,  150,    2, 0x08 /* Private */,
      22,    1,  153,    2, 0x08 /* Private */,
      23,    0,  156,    2, 0x08 /* Private */,
      24,    0,  157,    2, 0x08 /* Private */,
      25,    1,  158,    2, 0x08 /* Private */,
      27,    0,  161,    2, 0x08 /* Private */,
      28,    1,  162,    2, 0x08 /* Private */,
      30,    0,  165,    2, 0x08 /* Private */,
      31,    0,  166,    2, 0x08 /* Private */,
      32,    1,  167,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int,   10,   11,   12,   13,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 29,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void Gimbal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Gimbal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startSignal(); break;
        case 1: _t->sendAngleData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->sendDataSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->sig_ConnectState((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 4: _t->start(); break;
        case 5: _t->Init(); break;
        case 6: { float _r = _t->getAngleHorizontal();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 7: { float _r = _t->getAngleVertical();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->readData(); break;
        case 9: _t->connectedSlot(); break;
        case 10: _t->sendDataSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->VspeedSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->HspeedSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->btnRealtimeAckhaulOpenClicked(); break;
        case 14: _t->btnRealtimeAckhaulCloseClicked(); break;
        case 15: _t->comboBox_RealtimeAckhaulChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->handleDisconnected(); break;
        case 17: _t->handleError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 18: _t->btnConnectClicked(); break;
        case 19: _t->btnOneClickZeroingClicked(); break;
        case 20: _t->handle_checkBoxRealtimeAckhaulOpenSet((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Gimbal::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gimbal::startSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Gimbal::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gimbal::sendAngleData)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Gimbal::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gimbal::sendDataSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Gimbal::*)(int , QString , QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gimbal::sig_ConnectState)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Gimbal::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Gimbal.data,
    qt_meta_data_Gimbal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Gimbal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Gimbal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Gimbal.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Gimbal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void Gimbal::startSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Gimbal::sendAngleData(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Gimbal::sendDataSignal(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Gimbal::sig_ConnectState(int _t1, QString _t2, QString _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
