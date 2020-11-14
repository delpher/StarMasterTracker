#include <Arduino.h>
#include "Firmware.h"

void setup() {
    Firmware::init();
}

void loop() {
    Firmware::run();
}