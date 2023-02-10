#include "Led.h"
Led::Led(int pin) {
    _pin = pin;
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
}

void Led::live() {
    if (_blinking && _blinkTimer.available()) {
        toggle();
        _blinkTimer.restart();
    }
}

void Led::on() {
    setState(HIGH);
    _blinking = 0;
}

void Led::off() {
    setState(LOW);
    _blinking = 0;
}

void Led::toggle() {
    setState(!readState());
}

void Led::blink(int interval) {
    _blinkTimer.begin(interval);
    _blinking = 1;
}

void Led::setState(int state) {
    digitalWrite(_pin, state);
}

int Led::readState() {
    return digitalRead(_pin);
}