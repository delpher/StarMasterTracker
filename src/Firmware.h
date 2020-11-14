#ifndef STARMASTERTRACKER_FIRMWARE_H
#define STARMASTERTRACKER_FIRMWARE_H

#include "Led.h"
#include "Remote.h"

class Firmware {
private:
    static String mode;
    static Led *red_led;
    static Led *green_led;
    static Remote *remote;
public:
    static void init();
    static void run();
    static void data_received();
    static void play();
    static void pause();
    static void rewind();
};


#endif //STARMASTERTRACKER_FIRMWARE_H
