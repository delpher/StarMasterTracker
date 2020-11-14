#ifndef STARMASTERTRACKER_REMOTE_H
#define STARMASTERTRACKER_REMOTE_H

#include "../.pio/libdeps/nanoatmega328/IRremote/src/IRremote.h"

#define PLAY_BTN 0XC53A7986
#define PAUSE_BTN 0XC53AF906
#define REWIND_BTN 0XC53AB946

typedef void (*callback)();

class Remote {
private:
    callback data_handler;
    callback play_handler;
    callback pause_handler;
    callback rewind_handler;

    IRrecv *receiver;
public:
    Remote(int pin);
    void on_data(callback handler);
    void on_play(callback handler);
    void on_pause(callback handler);
    void on_rewind(callback handler);
    void update();
};

#endif //STARMASTERTRACKER_REMOTE_H