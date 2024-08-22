#include <Arduino.h>

const int servoPin = 13;
const int ledcChannel = 8;
const int frequency = 50;
const int resolution = 16;

void setup() {
    Serial.begin(9600);
    ledcSetup(ledcChannel, frequency, resolution);
    ledcAttachPin(servoPin, ledcChannel);
}

void loop() {
    float angle = 0;
    // int dutyCycle = map(angle, 0, 180, 3277, 6553);
    int dutyCycle;
    // ledcWrite(ledcChannel, dutyCycle);
    // for(angle = 1500; angle <= 12000; angle++) { // (0 - 180)
    //     // dutyCycle = map(angle, 0, 180, 3277, 6553);
    //     dutyCycle = angle;
    //     Serial.println(dutyCycle);
    //     ledcWrite(ledcChannel, dutyCycle);
    //     delay(1);
    // }
    // delay(2000);
    for(angle = 360; angle >= 0; angle--) { // (180 - 0)
        dutyCycle = map(angle, 0, 180, 3277, 6553);
        // dutyCycle = angle;
        Serial.println(dutyCycle);
        ledcWrite(ledcChannel, dutyCycle);
        delay(1);
    }
    delay(30000);
}
