/****************************************************************************
** Meta object code from reading C++ file 'stronglightoption.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../inc/stronglightoption.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stronglightoption.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StrongLightOption_t {
    QByteArrayData data[10];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StrongLightOption_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StrongLightOption_t qt_meta_stringdata_StrongLightOption = {
    {
QT_MOC_LITERAL(0, 0, 17), // "StrongLightOption"
QT_MOC_LITERAL(1, 18, 14), // "sig_TcpConnect"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 19), // "handle_ConnectState"
QT_MOC_LITERAL(4, 54, 10), // "deviceName"
QT_MOC_LITERAL(5, 65, 2), // "IP"
QT_MOC_LITERAL(6, 68, 4), // "Port"
QT_MOC_LITERAL(7, 73, 5), // "State"
QT_MOC_LITERAL(8, 79, 34), // "on_btn_tcpconnect_device_3_cl..."
QT_MOC_LITERAL(9, 114, 33) // "on_btn_tcpsave_device_3_1_cli..."

    },
    "StrongLightOption\0sig_TcpConnect\0\0"
    "handle_ConnectState\0deviceName\0IP\0"
    "Port\0State\0on_btn_tcpconnect_device_3_clicked\0"
    "on_btn_tcpsave_device_3_1_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StrongLightOption[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    4,   35,    2, 0x08 /* Private */,
       8,    0,   44,    2, 0x08 /* Private */,
       9,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int,    4,    5,    6,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void StrongLightOption::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StrongLightOption *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_TcpConnect(); break;
        case 1: _t->handle_ConnectState((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: _t->on_btn_tcpconnect_device_3_clicked(); break;
        case 3: _t->on_btn_tcpsave_device_3_1_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (StrongLightOption::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StrongLightOption::sig_TcpConnect)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject StrongLightOption::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_StrongLightOption.data,
    qt_meta_data_StrongLightOption,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *StrongLightOption::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StrongLightOption::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StrongLightOption.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int StrongLightOption::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void StrongLightOption::sig_TcpConnect()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
