#ifndef MOTOR_H
#define MOTOR_H

#include "enddevice.h"
#include <QObject>
#include <QByteArray>
class Motor : public EndDevice
{
public:
    Motor();
    const static QByteArray TURN_FORWARD;
    const static QByteArray TURN_REVERSAL;
    const static QByteArray TURN_STOP;
    const static QByteArray OPEN_LED1;
    const static QByteArray OPEN_LED2;
    const static QByteArray OPEN_LED3;
    const static QByteArray OPEN_LED4;
    const static QByteArray CLOSE_LED1;
    const static QByteArray CLOSE_LED2;
    const static QByteArray CLOSE_LED3;
    const static QByteArray CLOSE_LED4;
};

#endif // MOTOR_H
