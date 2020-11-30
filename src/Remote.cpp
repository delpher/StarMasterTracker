#include "Remote.h"
#include "pioneer_dvd_remote.h"

void null_handler() {}
void null_handler_p(uint32_t value) {}

Remote::Remote(int pin) {
    receiver = new IRrecv(pin);
    receiver->enableIRIn();
    receiver->blink13(true);
    play_handler = null_handler;
    pause_handler = null_handler;
    rewind_handler = null_handler;
    fast_fwd_handler = null_handler;
    fast_bwd_handler = null_handler;
    data_handler = null_handler_p;
}

void Remote::update() {
    decode_results results{};
    if (receiver->decode(&results)) {
        data_handler(results.value);
        switch (results.value) {
            case PLAY_BTN: play_handler(); break;
            case PAUSE_BTN: pause_handler(); break;
            case STOP_BTN: stop_handler(); break;
            case REWIND_BTN: rewind_handler(); break;
            case FAST_FWD_BTN: fast_fwd_handler(); break;
            case FAST_BWD_BTN: fast_bwd_handler(); break;
        }
        receiver->resume();
    }
}

void Remote::on_data(callback_p handler) {
    data_handler = handler;
}

void Remote::on_play(callback handler) {
    play_handler = handler;
}

void Remote::on_pause(callback handler) {
    pause_handler = handler;
}

void Remote::on_rewind(callback handler) {
    rewind_handler = handler;
}

void Remote::on_fast_fwd(callback handler) {
    fast_fwd_handler = handler;
}

void Remote::on_fast_bwd(callback handler) {
    fast_bwd_handler = handler;
}

void Remote::on_stop(callback handler) {
    stop_handler = handler;
}
