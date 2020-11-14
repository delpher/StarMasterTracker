#include "Remote.h"

void null_handler() {}

Remote::Remote(int pin) {
    receiver = new IRrecv(pin);
    receiver->enableIRIn();
    receiver->blink13(true);
    play_handler = null_handler;
    pause_handler = null_handler;
    rewind_handler = null_handler;
    data_handler = null_handler;
}

void Remote::update() {
    decode_results results{};
    if (receiver->decode(&results)) {
        data_handler();
        switch (results.value) {
            case PLAY_BTN: play_handler(); break;
            case PAUSE_BTN: pause_handler(); break;
            case REWIND_BTN: rewind_handler(); break;
        }
        receiver->resume();
    }
}

void Remote::on_data(callback handler) {
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
