//
// Created by guozihan on 2024/12/17.
//

#ifndef MY_TEST_DEMO_SENSORMANAGER_H
#define MY_TEST_DEMO_SENSORMANAGER_H
#include <Wire.h>
#include <Adafruit_MPU6050.h>
class SensorManager{
public:
    SensorManager();
    bool begin();
    void readData();
    void printData();

    float getAccelerationX();
    float getAccelerationY();
    float getAccelerationZ();
    float getGyroX();
    float getGyroY();
    float getGyroZ();
    float getTemperature();
    bool detectDoubleClick();

private:
    Adafruit_MPU6050 mpu;
    int16_t ax,ay,az;
    int16_t gx,gy,gz;
    int16_t temperature;

    float threshold = 2.5;
    unsigned long lastClickTime = 0;
    unsigned long clickTimeOut = 500;
    bool firstClickDetected = false;
};

#endif //MY_TEST_DEMO_SENSORMANAGER_H
