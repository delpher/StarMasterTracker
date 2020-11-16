#ifndef STARMASTERTRACKER_MOTOR_H
#define STARMASTERTRACKER_MOTOR_H

#include "../.pio/libdeps/nanoatmega328/StepperDriver/src/A4988.h"

#define MODE_STOP 0
#define MODE_FORWARD 1
#define MODE_BACKWARD 2

class Motor {
private:
    A4988 *stepper;
    short mode = MODE_STOP;
public:
    Motor(short stepPin, short dirPin, short ms1, short ms2, short ms3);
    void init();
    void update();
    void forward();
    void backward();
    void stop();
};


#endif //STARMASTERTRACKER_MOTOR_H
