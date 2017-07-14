#ifndef PWM_H
#define PWM_H

#include "enddevice.h"

class Pwm : public EndDevice
{
public:
    Pwm();
    static QByteArray RANGE;
    static QByteArray MSG_PWM;
};

#endif // PWM_H
