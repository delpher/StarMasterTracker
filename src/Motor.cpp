#include "Motor.h"

Motor::Motor(short stepPin, short dirPin, short ms1, short ms2, short ms3) {
    stepper = new A4988(200, dirPin, stepPin, ms1, ms2, ms3);
}

void Motor::init() {
    stepper->begin(forwardSpeed, 16);
}

void Motor::forward() {
    mode = TURNING_FORWARD;
    stepper->stop();
    stepper->setRPM(forwardSpeed);
}

void Motor::backward() {
    mode = TURNING_BACKWARD;
    stepper->stop();
    stepper->setRPM(200);
}

void Motor::stop() {
    mode = STOPPED;
    forwardSpeed = DEFAULT_SPEED;
}

void Motor::pause() {
    mode = STOPPED;
}

void Motor::speedUp() {
    forwardSpeed+=0.1;
    stepper->stop();
    stepper->setRPM(forwardSpeed);
}

void Motor::slowDown() {
    forwardSpeed-=0.1;
    stepper->stop();
    stepper->setRPM(forwardSpeed);
}

void Motor::update() {
    switch (mode) {
        case STOPPED: stepper->stop(); break;
        case TURNING_FORWARD:
            if (stepper->getStepsRemaining() == 0) {
                stepper->startMove(-3200);
            }
            break;
        case TURNING_BACKWARD:
            if (stepper->getStepsRemaining() == 0) {
                stepper->startMove(3200);
            }
            break;

    }
    stepper->nextAction();
}
