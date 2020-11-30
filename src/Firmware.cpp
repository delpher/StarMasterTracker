#include <HID.h>
#include "Firmware.h"

Remote *Firmware::remote;
Motor *Firmware::motor;

void Firmware::init() {
    //Serial.begin(9600);
    remote = new Remote(2);
    motor = new Motor(4, 3, 5, 6, 7);
    remote->on_data(Firmware::data_received);
    remote->on_play(Firmware::start);
    remote->on_pause(Firmware::pause);
    remote->on_stop(Firmware::stop);
    remote->on_rewind(Firmware::rewind);
    remote->on_fast_fwd(Firmware::speedUp);
    remote->on_fast_bwd(Firmware::slowDown);
    motor->init();
}

void Firmware::data_received(uint32_t value) {
    //Serial.println(value, HEX);
}

void Firmware::run() {
    remote->update();
    motor->update();
}

void Firmware::start() {
    motor->forward();
}

void Firmware::stop() {
    motor->stop();
}

void Firmware::pause() {
    motor->pause();
}

void Firmware::rewind() {
    motor->backward();
}

void Firmware::speedUp() {
    motor->speedUp();
}

void Firmware::slowDown() {
    motor->slowDown();
}
