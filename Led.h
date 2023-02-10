#ifndef Led_h
#define Led_h
#include "Arduino.h"
#include "Timer.h"
class Led {
  public:
    Led(int pin);
    void live();
    void on();
    void off();
    void toggle();
    void blink(int interval);
private:
    int _pin, _blinking;
    Timer _blinkTimer;
    void setState(int state);
    int readState();
};
#endif