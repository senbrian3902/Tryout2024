#include <Arduino.h>
#include <esp32_motor.hpp>
#include <BluetoothSerial.h>

// put function declarations here:
esp32_motor dc1(25, 26, 1, 2, 1500, 8); // banh xe ben trai
esp32_motor dc2(33, 32, 5, 6, 1500, 8); // banh xe ben phai

BluetoothSerial SerialBT;

char cmd;

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
        dc1.Run(100);
        dc2.Run(100);
        break;
      case 'B':
        dc1.Run(-100);
        dc2.Run(-100);
        break;
      case 'R':
        dc1.Run(-100);
        dc2.Run(100);
        break;
      case 'L':
        dc1.Run(100);
        dc2.Run(-100);
        break;
      case 'S':
        dc1.Stop();
        dc2.Stop();
        break;
      case 'G':
        dc2.Run(150);
        break;
      case 'I':
        dc1.Run(150);
        break;
      case 'H':
        dc1.Run(-150);
        break;
      case 'J':
        dc2.Run(-150);
        break;
      case 'D':
        dc1.Stop();
        dc2.Stop();
      }
        
      // case '0':
      //   100 = 0;
      // case '1':
      //   100 = 100;
      // case '2':
      //   100 = 200;
      // case '3':
      //   100 = 300;
      // case '4':
      //   100 = 400;
      // case '5':
      //   100 = 500;
      // case '6':
      //   100 = 600;
      // case '7':
      //   100 = 700;
      // case '8':
      //   100 = 800;
      // case '9':
      //   100 = 900;
      // case 'q':
      //   100 = 1000;
      
      // // case 'X':
      // //   for(long long angle = 0; angle <= 90; angle++) {
      // //     myServo.write(angle);
      // //     delay(10);
      // //   }
      // //   delay(1000);
      // //   for(long long angle = 90; angle > 0; angle--) {
      // //     myServo.write(angle);
      // //     delay(10);
      // //   }
      // //   
      // default:
      //   dc1.Stop();
      //   dc2.Stop();
        
    // }
  }
}

// put function definitions here:

