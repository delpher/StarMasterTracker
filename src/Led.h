//
// Created by delph on 14.11.2020.
//

#ifndef STARMASTERTRACKER_LED_H
#define STARMASTERTRACKER_LED_H

class Led {
    int led_pin;
    bool is_on;
    unsigned long on_from;
    unsigned long on_for;
public:
    Led(int pin);
    void blink(unsigned int duration);
    void update();
};

#endif //STARMASTERTRACKER_LED_H
