#ifndef STARMASTERTRACKER_FIRMWARE_H
#define STARMASTERTRACKER_FIRMWARE_H

#include "Remote.h"
#include "Motor.h"

class Firmware {
private:
    static Remote *remote;
    static Motor *motor;

    static void data_received(uint32_t value);
    static void start();
    static void stop();
    static void pause();
    static void rewind();
    static void speedUp();
    static void slowDown();

public:
    static void init();
    static void run();
};


#endif //STARMASTERTRACKER_FIRMWARE_H
