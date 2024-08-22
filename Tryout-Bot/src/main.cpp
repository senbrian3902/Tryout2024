#include <Arduino.h>
#include <esp32_motor.hpp>
#include <BluetoothSerial.h>
#include <ESP32Servo.h>

// put function declarations here:
esp32_motor dc1(25, 26, 4, 5, 1500, 8); // banh xe ben phai
esp32_motor dc2(33, 32, 2, 3, 1500, 8); // banh xe ben trai

BluetoothSerial SerialBT;
Servo myServo;

char cmd;
int speed = 100;
// const int servoPin = 13;
// const int ledcChannel = 8;
// const int frequency = 50;
// const int resolution = 16;
// float angle = 0;
// int dutyCycle = map(angle, 0, 180, 3277, 6553);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SerialBT.begin("Xe999");
  myServo.attach(13);
  myServo.write(0);
  // ledcSetup(ledcChannel, frequency, resolution); // servo
  // ledcAttachPin(servoPin, ledcChannel);
  Serial.println("Completed");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (SerialBT.available()) {
    cmd = char(SerialBT.read());
    // Serial.println(cmd);
    
    // ledcWrite(ledcChannel, dutyCycle);

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
        break;
      case '0':
        speed = 0;
        break;
      case '1':
        speed = 100;
        break;
      case '2':
        speed = 200;
        break;
      case '3':
        speed = 300;
        break;
      case '4':
        speed = 400;
        break;
      case '5':
        speed = 500;
        break;
      case '6':
        speed = 600;
        break;
      case '7':
        speed = 700;
        break;
      case '8':
        speed = 800;
        break;
      case '9':
        speed = 900;
        break;
      case 'q':
        speed = 1000;
        break;
      case 'X':
      //   for(angle = 0; angle <= 180; angle++) {
      //       dutyCycle = map(angle, 0, 180, 3277, 6553);
      //       ledcWrite(ledcChannel, dutyCycle);
      //       delay(1);
      //   }
      // case 'x':
      //   for(angle = 180; angle >= 0; angle--) {
      //       dutyCycle = map(angle, 0, 180, 3277, 6553);
      //       ledcWrite(ledcChannel, dutyCycle);
      //       delay(1);
      //   }
        for(long long angle = 0; angle <= 180; angle++) {
          myServo.write(angle);
          delay(2);
        }
        break;
      case 'x':
        for(long long angle = 180; angle > 0; angle--) {
          myServo.write(angle);
          delay(2);
        }
        break;
      default:
        dc1.Stop();
        dc2.Stop(); 
      }
  }
}

// put function definitions here:

