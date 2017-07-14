#include "enddevice.h"

EndDevice::EndDevice(QObject *parent) :
    QObject(parent),
    State(0)
{
}

void EndDevice::setState(int state){
    this->State = state;
}

int EndDevice::getState(){
    return this->State;
}
