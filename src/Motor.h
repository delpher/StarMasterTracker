#ifndef STARMASTERTRACKER_MOTOR_H
#define STARMASTERTRACKER_MOTOR_H

#include "../.pio/libdeps/nanoatmega328/StepperDriver/src/A4988.h"

#define STOPPED 0
#define TURNING_FORWARD 1
#define TURNING_BACKWARD 2
#define DEFAULT_SPEED 2.5f;

class Motor {
private:
    A4988 *stepper;
    short mode = STOPPED;
    float forwardSpeed = DEFAULT_SPEED;
public:
    Motor(short stepPin, short dirPin, short ms1, short ms2, short ms3);
    void init();
    void update();
    void forward();
    void backward();
    void speedUp();
    void slowDown();
    void pause();
    void stop();
};


#endif //STARMASTERTRACKER_MOTOR_H
