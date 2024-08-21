#include <Arduino.h>
#include <esp32_motor.hpp>
#include <BluetoothSerial.h>

// put function declarations here:
esp32_motor dc1(25, 26, 1, 2, 1500, 8); // banh xe ben trai
esp32_motor dc2(33, 32, 5, 6, 1500, 8); // banh xe ben phai

BluetoothSerial SerialBT;

char cmd;

int speed = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SerialBT.begin("Xe999");
  Serial.println("Completed");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (SerialBT.available()) {
    cmd = char(SerialBT.read());
    // Serial.println(cmd);

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
      
      // // case 'X':
      // //   for(long long angle = 0; angle <= 90; angle++) {
      // //     myServo.write(angle);
      // //     delay(10);
      // //   }
      // //   delay(speed0);
      // //   for(long long angle = 90; angle > 0; angle--) {
      // //     myServo.write(angle);
      // //     delay(10);
      // //   }
      // //   
      default:
        dc1.Stop();
        dc2.Stop(); 
    }
  }
}

// put function definitions here:

