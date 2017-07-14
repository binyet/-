#ifndef SERIALCOM_H
#define SERIALCOM_H

#include <QDebug>
#include <QObject>
#include <QMainWindow>
#include "posix_qextserialport.h"
#include <QTimer>
class SerialCom : public QObject
{
    Q_OBJECT
public:
    explicit SerialCom(QObject *parent = 0);
    Posix_QextSerialPort *myCom;
    int comState;
    QTimer *time;
    bool openCom();
    bool closeCom();
    QTimer* getTimer();
    int getComState();
    int writeToSerial(const QByteArray &byte);

signals:
    void receiveMsgFromSerial(QByteArray);
public slots:
    void readFromSerial();
};

#endif // SERIALCOM_H
