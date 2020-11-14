#include <HID.h>
#include "Led.h"

Led::Led(int pin) {
    led_pin = pin;
    pinMode(led_pin, OUTPUT);
}

void Led::blink(unsigned int duration) {
    if (is_on) return;
    is_on = true;
    on_from = millis();
    on_for = duration;
    digitalWrite(led_pin,HIGH);
}

void Led::update() {
    if (is_on) {
        unsigned long current_millis = millis();
        if (current_millis - on_from >= on_for) {
            digitalWrite(led_pin,LOW);
            is_on = false;
        }
    }
}
