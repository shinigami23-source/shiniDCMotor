
#ifndef shiniDCMotor_h
#define shiniDCMotor_h
#include <Arduino.h>

class shiniDCMotor{

private:
    uint8_t pin0, pin1,dutyPin, state;
    uint16_t duty;
public:
    void begin(uint8_t _pin0, uint8_t _pin1, uint8_t _dutyPin, uint32_t _freq, uint8_t _resolutionn);
    void forward();
    void reverse();
    void stop();
    void setDuty(uint16_t);
    uint16_t getDuty();
    uint8_t getState();
};

#endif
