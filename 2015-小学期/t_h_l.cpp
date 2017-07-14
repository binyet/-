#include "t_h_l.h"

T_H_L::T_H_L()
{
    temp = 0;
    humi = 0;
    light = 0;
}

void T_H_L::setValue(int temp, int humi, float light){
    this->temp = temp;
    this->humi = humi;
    this->light = light;
}

void T_H_L::setValue(QByteArray &byte){
    unsigned char adc_value[2];
    temp = (byte[5] << 8) + byte[6];//计算温度值公式
    humi = (byte[7] << 8) + byte[8];//计算湿度值公式
    adc_value[0] = byte[10];
    adc_value[1] = byte[9];
    adc_value[0] = adc_value[0] >> 2;
    light = (adc_value[1]*256 + adc_value[0]) * 3.3 / 8192;
    light = light / 4;
    light = light * 913;

}

int T_H_L::getTemp(){
    return temp;
}

int T_H_L::getHumi(){
    return humi;
}

float T_H_L::getLight(){
    return light;
}
