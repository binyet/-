#ifndef T_H_L_H
#define T_H_L_H

#include "enddevice.h"
#include <QObject>

class T_H_L : public EndDevice
{
public:
    T_H_L();
    void setValue(QByteArray&);
    void setValue(int ,int , float);
    int getTemp();
    int getHumi();
    float getLight();

    int temp;
    int humi;
    float light;
};

#endif // T_H_L_H
