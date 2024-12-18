//
// Created by guozihan on 2024/12/17.
//
#include "SensorManager.h"

SensorManager::SensorManager() {
    //init
}

bool SensorManager::begin() {
    Wire.begin();
    return mpu.begin();
}

void SensorManager::readData() {
    sensors_event_t a, g, tempData;
    mpu.getEvent(&a, &g, &tempData);
    ax = a.acceleration.x;
    ay = a.acceleration.y;
    az = a.acceleration.z;
    gx = g.gyro.x;
    gy = g.gyro.y;
    gz = g.gyro.z;
    temperature = tempData.temperature;
}

void SensorManager::printData() {
    // 打印加速度数据
    Serial.print("加速度 - X: ");
    Serial.print(ax);
    Serial.print(" Y: ");
    Serial.print(ay);
    Serial.print(" Z: ");
    Serial.println(az);

    // 打印陀螺仪数据
    Serial.print("陀螺仪 - X: ");
    Serial.print(gx);
    Serial.print(" Y: ");
    Serial.print(gy);
    Serial.print(" Z: ");
    Serial.println(gz);

    // 打印温度数据
    Serial.print("温度: ");
    Serial.println(temperature);
}

float SensorManager::getAccelerationX() {
    return ax;
}

float SensorManager::getAccelerationY() {
    return ay;
}

float SensorManager::getAccelerationZ() {
    return az;
}

float SensorManager::getGyroX() {
    return gx;
}

float SensorManager::getGyroY() {
    return gy;
}

float SensorManager::getGyroZ() {
    return gz;
}

float SensorManager::getTemperature() {
    return temperature;
}

bool SensorManager::detectDoubleClick() {
    if (az < -threshold) {
        if (!firstClickDetected) {
            firstClickDetected = true;
            lastClickTime = millis();
        } else {
            if (millis() - lastClickTime < clickTimeOut) {
                firstClickDetected = false;
                return true;
            }
        }
    }
    return false;
}
