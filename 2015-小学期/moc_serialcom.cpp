/****************************************************************************
** Meta object code from reading C++ file 'serialcom.h'
**
** Created: Mon May 15 16:55:50 2017
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "serialcom.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialcom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SerialCom[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      44,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SerialCom[] = {
    "SerialCom\0\0receiveMsgFromSerial(QByteArray)\0"
    "readFromSerial()\0"
};

const QMetaObject SerialCom::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SerialCom,
      qt_meta_data_SerialCom, 0 }
};

const QMetaObject *SerialCom::metaObject() const
{
    return &staticMetaObject;
}

void *SerialCom::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SerialCom))
        return static_cast<void*>(const_cast< SerialCom*>(this));
    return QObject::qt_metacast(_clname);
}

int SerialCom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: receiveMsgFromSerial((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: readFromSerial(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void SerialCom::receiveMsgFromSerial(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
