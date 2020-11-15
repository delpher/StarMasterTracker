#include "Motor.h"

Motor::Motor(short stepPin, short dirPin, short ms1, short ms2, short ms3) {
    stepper = new A4988(200, dirPin, stepPin, ms1, ms2, ms3);
}

void Motor::init() {
    stepper->begin(2.5, 16);
}

void Motor::forward() {
    mode = MODE_FORWARD;
    stepper->setRPM(2.5);
}

void Motor::backward() {
    mode = MODE_BACKWARD;
    stepper->setRPM(200);
}

void Motor::stop() {
    mode = MODE_STOP;
}

void Motor::update() {
    switch (mode) {
        case MODE_STOP: {
            stepper->stop();
            break;
        }
        case MODE_FORWARD: {
            stepper->rotate(-1);
            break;
        }
        case MODE_BACKWARD: {
            stepper->rotate(1);
            break;
        }
    }
}
