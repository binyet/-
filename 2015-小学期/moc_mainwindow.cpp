/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon May 15 16:55:46 2017
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      28,   11,   11,   11, 0x08,
      51,   11,   11,   11, 0x08,
      68,   11,   11,   11, 0x08,
      95,   11,   11,   11, 0x08,
     123,   11,   11,   11, 0x08,
     147,   11,   11,   11, 0x08,
     167,   11,   11,   11, 0x08,
     185,   11,   11,   11, 0x08,
     203,   11,   11,   11, 0x08,
     221,   11,   11,   11, 0x08,
     239,   11,   11,   11, 0x08,
     265,   11,   11,   11, 0x08,
     289,   11,   11,   11, 0x08,
     312,   11,   11,   11, 0x08,
     323,   11,   11,   11, 0x08,
     348,   11,   11,   11, 0x08,
     355,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0addLog(QString)\0"
    "on_comButton_clicked()\0showLog(QString)\0"
    "on_forwardButton_clicked()\0"
    "on_reversalButton_clicked()\0"
    "on_stopButton_clicked()\0process(QByteArray)\0"
    "on_LED1_clicked()\0on_LED2_clicked()\0"
    "on_LED3_clicked()\0on_LED4_clicked()\0"
    "on_Motor_Button_clicked()\0"
    "on_LED_Button_clicked()\0on_thlButton_clicked()\0"
    "showTime()\0on_IntelButton_clicked()\0"
    "test()\0on_lcd_temp_overflow()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addLog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: on_comButton_clicked(); break;
        case 2: showLog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: on_forwardButton_clicked(); break;
        case 4: on_reversalButton_clicked(); break;
        case 5: on_stopButton_clicked(); break;
        case 6: process((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: on_LED1_clicked(); break;
        case 8: on_LED2_clicked(); break;
        case 9: on_LED3_clicked(); break;
        case 10: on_LED4_clicked(); break;
        case 11: on_Motor_Button_clicked(); break;
        case 12: on_LED_Button_clicked(); break;
        case 13: on_thlButton_clicked(); break;
        case 14: showTime(); break;
        case 15: on_IntelButton_clicked(); break;
        case 16: test(); break;
        case 17: on_lcd_temp_overflow(); break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::addLog(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
