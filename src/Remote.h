#ifndef STARMASTERTRACKER_REMOTE_H
#define STARMASTERTRACKER_REMOTE_H

#include "../.pio/libdeps/nanoatmega328/IRremote/src/IRremote.h"

typedef void (*callback)();

typedef void (*callback_p)(uint32_t value);

class Remote {
private:
    callback_p data_handler;
    callback play_handler;
    callback pause_handler;
    callback rewind_handler;
    callback fast_fwd_handler;
    callback fast_bwd_handler;
    callback stop_handler;

    IRrecv *receiver;
public:
    Remote(int pin);
    void on_data(callback_p handler);
    void on_play(callback handler);
    void on_pause(callback handler);
    void on_stop(callback handler);
    void on_rewind(callback handler);
    void on_fast_fwd(callback handler);
    void on_fast_bwd(callback handler);

    void update();
};

#endif //STARMASTERTRACKER_REMOTE_H
