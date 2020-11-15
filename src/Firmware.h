#ifndef STARMASTERTRACKER_FIRMWARE_H
#define STARMASTERTRACKER_FIRMWARE_H

#include "Remote.h"
#include "Motor.h"

class Firmware {
private:
    static Remote *remote;
    static Motor *motor;
public:
    static void init();
    static void run();
    static void data_received();
    static void play();
    static void pause();
    static void rewind();
};


#endif //STARMASTERTRACKER_FIRMWARE_H
