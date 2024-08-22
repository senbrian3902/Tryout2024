#include <Arduino.h>
#include <esp32_motor.hpp>
#include <BluetoothSerial.h>
// #include <ESP32Servo.h>

// put function declarations here:
esp32_motor dc1(25, 26, 1, 2, 1500, 8); // banh xe ben trai
esp32_motor dc2(33, 32, 5, 6, 1500, 8); // banh xe ben phai

BluetoothSerial SerialBT;
// Servo myServo;

char cmd;
int speed = 100;
const int servoPin = 13;
const int ledcChannel = 8;
const int frequency = 50;
const int resolution = 16;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SerialBT.begin("Xe999");
  // myServo.attach(25);
  // myServo.write(0);
  ledcSetup(ledcChannel, frequency, resolution); // servo
  ledcAttachPin(servoPin, ledcChannel);
  Serial.println("Completed");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (SerialBT.available()) {
    cmd = char(SerialBT.read());
    // Serial.println(cmd);
    float angle = 0;
    int dutyCycle = map(angle, 0, 180, 3277, 6553);

    switch (cmd) {
      case 'F':
        dc1.Run(speed);
        dc2.Run(speed);
        break;
      case 'B':
        dc1.Run(-speed);
        dc2.Run(-speed);
        break;
      case 'R':
        dc1.Run(-speed);
        dc2.Run(speed);
        break;
      case 'L':
        dc1.Run(speed);
        dc2.Run(-speed);
        break;
      case 'S':
        dc1.Stop();
        dc2.Stop();
        break;
      case 'G':
        dc2.Run(speed + 50);
        break;
      case 'I':
        dc1.Run(speed + 50);
        break;
      case 'H':
        dc1.Run(-speed - 50);
        break;
      case 'J':
        dc2.Run(-speed - 50);
        break;
      case 'D':
        dc1.Stop();
        dc2.Stop();
      case '0':
        speed = 0;
      case '1':
        speed = 100;
      case '2':
        speed = 200;
      case '3':
        speed = 300;
      case '4':
        speed = 400;
      case '5':
        speed = 500;
      case '6':
        speed = 600;
      case '7':
        speed = 700;
      case '8':
        speed = 800;
      case '9':
        speed = 900;
      case 'q':
        speed = 1000;
      case 'X': 
        ledcWrite(ledcChannel, dutyCycle);
        delay(1000);
        for(angle = 0; angle <= 180; angle++) {
            dutyCycle = map(angle, 0, 180, 3277, 6553);
            ledcWrite(ledcChannel, dutyCycle);
            delay(1);
        }
      case 'x':
        for(angle = 180; angle >= 0; angle--) {
            dutyCycle = map(angle, 0, 180, 3277, 6553);
            ledcWrite(ledcChannel, dutyCycle);
            delay(1);
        }
      //   for(long long angle = 0; angle <= 90; angle++) {
      //     myServo.write(angle);
      //     delay(10);
      //   }
      //   delay(1000);
      //   for(long long angle = 90; angle > 0; angle--) {
      //     myServo.write(angle);
      //     delay(10);
      //   }
      default:
        dc1.Stop();
        dc2.Stop(); 
    }
  }
}

// put function definitions here:

