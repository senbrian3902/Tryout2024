#include <Arduino.h>
#include <esp32_motor.hpp>

void setup() {
    Serial.begin(9600);
    Serial.println("Completed");
    pinMode(25, OUTPUT);
    pinMode(26, OUTPUT);
}

void loop() {
    digitalWrite(25, HIGH);
    digitalWrite(26, LOW);
}
