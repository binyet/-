#include "motor.h"

Motor::Motor()
{
}

const QByteArray Motor::TURN_FORWARD("\x40\x06\x01\x06\x0a\x57", 6);
const QByteArray Motor::TURN_REVERSAL("\x40\x06\x01\x06\x0b\x58", 6);
const QByteArray Motor::TURN_STOP("\x40\x06\x01\x06\x0c\x59", 6);
const QByteArray Motor::OPEN_LED1("\x40\x06\x01\x06\x01\x4e", 6);
const QByteArray Motor::CLOSE_LED1("\x40\x06\x01\x06\x02\x4f", 6);
const QByteArray Motor::OPEN_LED2("\x40\x06\x01\x06\x03\x50", 6);
const QByteArray Motor::CLOSE_LED2("\x40\x06\x01\x06\x04\x51", 6);
const QByteArray Motor::OPEN_LED3("\x40\x06\x01\x06\x05\x52", 6);
const QByteArray Motor::CLOSE_LED3("\x40\x06\x01\x06\x06\x53", 6);
const QByteArray Motor::OPEN_LED4("\x40\x06\x01\x06\x07\x54", 6);
const QByteArray Motor::CLOSE_LED4("\x40\x06\x01\x06\x08\x55", 6);
