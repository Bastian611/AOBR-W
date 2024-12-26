/****************************************************************************
** Meta object code from reading C++ file 'acousticcontroludp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../inc/acousticcontroludp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'acousticcontroludp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AcousticcontrolUDP_t {
    QByteArrayData data[22];
    char stringdata0[257];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AcousticcontrolUDP_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AcousticcontrolUDP_t qt_meta_stringdata_AcousticcontrolUDP = {
    {
QT_MOC_LITERAL(0, 0, 18), // "AcousticcontrolUDP"
QT_MOC_LITERAL(1, 19, 11), // "startSignal"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 16), // "sig_ConnectState"
QT_MOC_LITERAL(4, 49, 10), // "deviceName"
QT_MOC_LITERAL(5, 60, 2), // "IP"
QT_MOC_LITERAL(6, 63, 4), // "Port"
QT_MOC_LITERAL(7, 68, 11), // "SocketState"
QT_MOC_LITERAL(8, 80, 5), // "start"
QT_MOC_LITERAL(9, 86, 4), // "Init"
QT_MOC_LITERAL(10, 91, 8), // "readData"
QT_MOC_LITERAL(11, 100, 8), // "sendData"
QT_MOC_LITERAL(12, 109, 22), // "AudioInStreamReadyRead"
QT_MOC_LITERAL(13, 132, 19), // "AudioInStreamStatus"
QT_MOC_LITERAL(14, 152, 13), // "QAudio::State"
QT_MOC_LITERAL(15, 166, 13), // "stopRecording"
QT_MOC_LITERAL(16, 180, 19), // "btnBroadcastClicked"
QT_MOC_LITERAL(17, 200, 22), // "SliderCapVolumeChanged"
QT_MOC_LITERAL(18, 223, 12), // "TimeoutSetIP"
QT_MOC_LITERAL(19, 236, 12), // "handle_IPSet"
QT_MOC_LITERAL(20, 249, 2), // "ip"
QT_MOC_LITERAL(21, 252, 4) // "port"

    },
    "AcousticcontrolUDP\0startSignal\0\0"
    "sig_ConnectState\0deviceName\0IP\0Port\0"
    "SocketState\0start\0Init\0readData\0"
    "sendData\0AudioInStreamReadyRead\0"
    "AudioInStreamStatus\0QAudio::State\0"
    "stopRecording\0btnBroadcastClicked\0"
    "SliderCapVolumeChanged\0TimeoutSetIP\0"
    "handle_IPSet\0ip\0port"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AcousticcontrolUDP[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    4,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   89,    2, 0x0a /* Public */,
       9,    0,   90,    2, 0x0a /* Public */,
      10,    0,   91,    2, 0x08 /* Private */,
      11,    0,   92,    2, 0x08 /* Private */,
      12,    0,   93,    2, 0x08 /* Private */,
      13,    1,   94,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,
      16,    0,   98,    2, 0x08 /* Private */,
      17,    1,   99,    2, 0x08 /* Private */,
      18,    0,  102,    2, 0x08 /* Private */,
      19,    2,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int,    4,    5,    6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   20,   21,

       0        // eod
};

void AcousticcontrolUDP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AcousticcontrolUDP *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startSignal(); break;
        case 1: _t->sig_ConnectState((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: _t->start(); break;
        case 3: _t->Init(); break;
        case 4: _t->readData(); break;
        case 5: _t->sendData(); break;
        case 6: _t->AudioInStreamReadyRead(); break;
        case 7: _t->AudioInStreamStatus((*reinterpret_cast< QAudio::State(*)>(_a[1]))); break;
        case 8: _t->stopRecording(); break;
        case 9: _t->btnBroadcastClicked(); break;
        case 10: _t->SliderCapVolumeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->TimeoutSetIP(); break;
        case 12: _t->handle_IPSet((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAudio::State >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AcousticcontrolUDP::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AcousticcontrolUDP::startSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AcousticcontrolUDP::*)(int , QString , QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AcousticcontrolUDP::sig_ConnectState)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AcousticcontrolUDP::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AcousticcontrolUDP.data,
    qt_meta_data_AcousticcontrolUDP,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AcousticcontrolUDP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AcousticcontrolUDP::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AcousticcontrolUDP.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AcousticcontrolUDP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void AcousticcontrolUDP::startSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AcousticcontrolUDP::sig_ConnectState(int _t1, QString _t2, QString _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
