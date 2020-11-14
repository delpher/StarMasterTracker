#include <HID.h>
#include "Firmware.h"

Led *Firmware::red_led;
Led *Firmware::green_led;
Remote *Firmware::remote;
String Firmware::mode;

void Firmware::init() {
    Serial.begin(9600);
    red_led = new Led(8);
    green_led = new Led(9);
    remote = new Remote(7);
    remote->on_data(Firmware::data_received);
    remote->on_play(Firmware::play);
    remote->on_pause(Firmware::pause);
    remote->on_rewind(Firmware::rewind);
}

void Firmware::data_received() {
    red_led->blink(10);
    green_led->blink(10);
}

void Firmware::run() {
    red_led->update();
    green_led->update();
    remote->update();
}

void Firmware::play() {
    if (mode == "PLAYING") return;
    mode = "PLAYING";
    Serial.println("PLAY");
}

void Firmware::pause() {
    if (mode == "PAUSED") return;
    mode = "PAUSED";
    Serial.println("PAUSE");
}

void Firmware::rewind() {
    if (mode == "REWINDING") return;
    mode = "REWINDING";
    Serial.println("REWIND");
}

