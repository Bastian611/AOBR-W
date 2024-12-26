/****************************************************************************
** Meta object code from reading C++ file 'acousticcontroloption.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../inc/acousticcontroloption.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'acousticcontroloption.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AcousticcontrolOption_t {
    QByteArrayData data[20];
    char stringdata0[351];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AcousticcontrolOption_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AcousticcontrolOption_t qt_meta_stringdata_AcousticcontrolOption = {
    {
QT_MOC_LITERAL(0, 0, 21), // "AcousticcontrolOption"
QT_MOC_LITERAL(1, 22, 18), // "sig_btn_tcpconnect"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 9), // "sig_IPSet"
QT_MOC_LITERAL(4, 52, 2), // "ip"
QT_MOC_LITERAL(5, 55, 4), // "port"
QT_MOC_LITERAL(6, 60, 21), // "sig_getUploadFilePath"
QT_MOC_LITERAL(7, 82, 17), // "sig_btnUploadFile"
QT_MOC_LITERAL(8, 100, 13), // "sig_btnOneKey"
QT_MOC_LITERAL(9, 114, 19), // "handle_ConnectState"
QT_MOC_LITERAL(10, 134, 10), // "deviceName"
QT_MOC_LITERAL(11, 145, 2), // "IP"
QT_MOC_LITERAL(12, 148, 4), // "Port"
QT_MOC_LITERAL(13, 153, 5), // "State"
QT_MOC_LITERAL(14, 159, 34), // "on_btn_tcpconnect_device_2_cl..."
QT_MOC_LITERAL(15, 194, 33), // "on_btn_tcpsave_device_2_1_cli..."
QT_MOC_LITERAL(16, 228, 33), // "on_btn_udpsave_device_2_1_cli..."
QT_MOC_LITERAL(17, 262, 42), // "on_pushButton_uploadFilePathC..."
QT_MOC_LITERAL(18, 305, 24), // "on_btnUploadFile_clicked"
QT_MOC_LITERAL(19, 330, 20) // "on_btnOneKey_clicked"

    },
    "AcousticcontrolOption\0sig_btn_tcpconnect\0"
    "\0sig_IPSet\0ip\0port\0sig_getUploadFilePath\0"
    "sig_btnUploadFile\0sig_btnOneKey\0"
    "handle_ConnectState\0deviceName\0IP\0"
    "Port\0State\0on_btn_tcpconnect_device_2_clicked\0"
    "on_btn_tcpsave_device_2_1_clicked\0"
    "on_btn_udpsave_device_2_1_clicked\0"
    "on_pushButton_uploadFilePathChoose_clicked\0"
    "on_btnUploadFile_clicked\0on_btnOneKey_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AcousticcontrolOption[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    2,   75,    2, 0x06 /* Public */,
       6,    1,   80,    2, 0x06 /* Public */,
       7,    0,   83,    2, 0x06 /* Public */,
       8,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    4,   85,    2, 0x08 /* Private */,
      14,    0,   94,    2, 0x08 /* Private */,
      15,    0,   95,    2, 0x08 /* Private */,
      16,    0,   96,    2, 0x08 /* Private */,
      17,    0,   97,    2, 0x08 /* Private */,
      18,    0,   98,    2, 0x08 /* Private */,
      19,    0,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    5,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int,   10,   11,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AcousticcontrolOption::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AcousticcontrolOption *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_btn_tcpconnect(); break;
        case 1: _t->sig_IPSet((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->sig_getUploadFilePath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sig_btnUploadFile(); break;
        case 4: _t->sig_btnOneKey(); break;
        case 5: _t->handle_ConnectState((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 6: _t->on_btn_tcpconnect_device_2_clicked(); break;
        case 7: _t->on_btn_tcpsave_device_2_1_clicked(); break;
        case 8: _t->on_btn_udpsave_device_2_1_clicked(); break;
        case 9: _t->on_pushButton_uploadFilePathChoose_clicked(); break;
        case 10: _t->on_btnUploadFile_clicked(); break;
        case 11: _t->on_btnOneKey_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AcousticcontrolOption::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AcousticcontrolOption::sig_btn_tcpconnect)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AcousticcontrolOption::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AcousticcontrolOption::sig_IPSet)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AcousticcontrolOption::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AcousticcontrolOption::sig_getUploadFilePath)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AcousticcontrolOption::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AcousticcontrolOption::sig_btnUploadFile)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (AcousticcontrolOption::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AcousticcontrolOption::sig_btnOneKey)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AcousticcontrolOption::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_AcousticcontrolOption.data,
    qt_meta_data_AcousticcontrolOption,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AcousticcontrolOption::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AcousticcontrolOption::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AcousticcontrolOption.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AcousticcontrolOption::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void AcousticcontrolOption::sig_btn_tcpconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AcousticcontrolOption::sig_IPSet(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AcousticcontrolOption::sig_getUploadFilePath(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AcousticcontrolOption::sig_btnUploadFile()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void AcousticcontrolOption::sig_btnOneKey()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
