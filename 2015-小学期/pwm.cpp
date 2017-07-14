#include "pwm.h"

Pwm::Pwm()
{
}

QByteArray Pwm::RANGE("\x40\x06\x01\x09\x00\x50", 6);
QByteArray Pwm::MSG_PWM("\x40\x06\x01\x09\x05\x55", 6);
