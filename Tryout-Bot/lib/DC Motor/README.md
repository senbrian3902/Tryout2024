# ESP32 DC Motor Basic controller

> This library can attach each couple of GPIO pins to a couple of pwm channels
> Each motor needs 2 PWM pins to run in 2 directions

## Tutorial

* Init lib by making an "esp32_motor" class object
> Definition
```
esp32_motor::esp32_motor(Forward_pin, Backward_pin, Forward_PWM_channel, Backward_PWM_channel, PWM_frequency, PWM_resolution);
```
> Example
```
esp32_motor mymotor(31, 32, 0, 1, 3000, 8);
```

* Run motor: 
> Definition
```
esp32_motor::Run(int);
```
> Example
```
// code
mymotor.Run(250);
// code
mymotor.Run(-250);
// code
```

* Brake motor:
> Definition
```
esp32_motor::Stop();
```
> Example
```
mymotor.Stop();
```