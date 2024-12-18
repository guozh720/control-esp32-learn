#include <Arduino.h>
#include <WiFi.h>
#include "utils/Logger.h"
#include "sensor/SensorManager.h"

#define LED_PIN_D4 12  // D4 LED连接在 GPIO12
#define LED_PIN_D5 13  // D5 LED连接在 GPIO13

const char* ssid = "405";
const char* passwd = "66668888";

void setup() {
    Serial.begin(9600);
    while (!Serial);  // 等待串口初始化
    Serial.println("Setup started");
    pinMode(LED_PIN_D4, OUTPUT);  // 设置 GPIO12 为输出模式
    pinMode(LED_PIN_D5, OUTPUT);  // 设置 GPIO13 为输出模式
    Serial.println("LED_PIN D4 and D5 set to OUTPUT");

    Serial.println("connecting to WIFI....");
    WiFi.begin(ssid,passwd);
    while (WiFiClass::status()!=WL_CONNECTED){
        delay(1000);
        Serial.println(".");
    }
    // 一旦连接，显示 IP 地址
    Serial.println("\nWi-Fi连接成功！");
    Serial.print("\nIP 地址: ");
    Serial.println(WiFi.localIP());
}

void loop() {
    // 控制 D4 LED
    digitalWrite(LED_PIN_D4, HIGH);  // 点亮 D4 LED
    Serial.println("D4 LED ON");
    delay(1000);  // 延迟1秒

    digitalWrite(LED_PIN_D4, LOW);   // 熄灭 D4 LED
    Serial.println("D4 LED OFF");
    delay(1000);  // 延迟1秒

    // 控制 D5 LED
    digitalWrite(LED_PIN_D5, HIGH);  // 点亮 D5 LED
    Serial.println("D5 LED ON");
    delay(1000);  // 延迟1秒

    digitalWrite(LED_PIN_D5, LOW);   // 熄灭 D5 LED
    Serial.println("D5 LED OFF");
    delay(1000);  // 延迟1秒
}
