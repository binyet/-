#include "serialcom.h"

SerialCom::SerialCom(QObject *parent) :
    QObject(parent),
    myCom(0),
    comState(0)
{
    time = new QTimer();
    time->start(100);
    connect(this->time, SIGNAL(timeout()), this, SLOT(readFromSerial()));
    //qDebug() << comState;
}

void SerialCom::readFromSerial()
{
    if(myCom && 1 == comState)
    {
        QByteArray byte = myCom->readAll();
        if(!byte.isEmpty())
            emit receiveMsgFromSerial(byte);
    }
}

int SerialCom::writeToSerial(const QByteArray &byte)
{
    if(myCom && 1 == comState)
    {
        return myCom->write(byte);
    }
    return -1;
}

bool SerialCom::openCom()
{
    if(myCom)
    {
        closeCom();
    }
    else
    {
        QString com_name = "/dev/ttySAC1";
        myCom = new Posix_QextSerialPort(com_name, QextSerialBase::Polling);
    }
    myCom->open(QIODevice::ReadWrite);
    if(myCom->isOpen())
    {
        comState = 1;
        myCom->setBaudRate(BAUD115200);
        myCom->setDataBits(DATA_8);
        myCom->setParity(PAR_NONE);
        myCom->setStopBits(STOP_1);
        myCom->setFlowControl(FLOW_OFF);
        myCom->setTimeout(50);
        return true;
    }
    else
    {
        comState = 0;
        return false;
    }
}

bool SerialCom::closeCom()
{
    if(myCom && 0 != comState)
    {
        myCom->close();
    }
    comState = 0;
    return true;
}


QTimer* SerialCom::getTimer()
{
    return time;
}

int SerialCom::getComState()
{
    return comState;
}


