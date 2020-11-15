#include <HID.h>
#include "Firmware.h"

Remote *Firmware::remote;
Motor *Firmware::motor;

void Firmware::init() {
    Serial.begin(9600);
    remote = new Remote(2);
    motor = new Motor(4, 3, 5, 6, 7);
    remote->on_data(Firmware::data_received);
    remote->on_play(Firmware::play);
    remote->on_pause(Firmware::pause);
    remote->on_rewind(Firmware::rewind);
    motor->init();
}

void Firmware::data_received() {
}

void Firmware::run() {
    remote->update();
    motor->update();
}

void Firmware::play() {
    motor->forward();
}

void Firmware::pause() {
    motor->stop();
}

void Firmware::rewind() {
    motor->backward();
}