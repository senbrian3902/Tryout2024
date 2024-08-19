#include <esp32_motor.hpp>

esp32_motor::esp32_motor(int8_t forward_pin, int8_t backward_pin, int8_t channel_number_forward, int8_t channel_number_backward, uint freq, uint8_t res) {
    ledcAttachPin(forward_pin, channel_number_forward);
    ledcAttachPin(backward_pin, channel_number_backward);
    forward = channel_number_forward;
    backward = channel_number_backward;
    ledcSetup(channel_number_backward, freq, res);
    ledcSetup(channel_number_forward, freq, res);
    maxPWM = pow(2, res) - 1;
}

void esp32_motor::Run(int PWM) {
    ledcWrite(forward, (PWM>0)?(PWM):(0));
    ledcWrite(backward, (PWM>0)?(0):(-PWM));
}

void esp32_motor::Stop() {
    ledcWrite(forward, maxPWM);
    ledcWrite(backward, maxPWM);
}