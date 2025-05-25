#include <shiniDCMotor.h>

void shiniDCMotor::begin(uint8_t _pin0, uint8_t _pin1, uint8_t _dutyPin, uint32_t _freq, uint8_t _resolution){
    pin0 = _pin0;
    pin1 = _pin1;
    dutyPin = _dutyPin;
    
    pinMode(pin0, OUTPUT);
    pinMode(pin1, OUTPUT);

    #if defined(ARDUINO_ARCH_ESP32)  //use hardware PWM if ESP32
        ledcAttach(dutyPin, _freq, _resolution);
    #else //or use standard Arduino libraries
        pinMode(dutyPin, OUTPUT);
        analogWriteResolution( dutyPin, _resolution);
        analogWriteFrequency( dutyPin, _freq);
    #endif
 

}
void shiniDCMotor::stop(){
    digitalWrite(pin0, 0);
    digitalWrite(pin1, 0);
    state = 1;
}

void shiniDCMotor::forward(){
    digitalWrite(pin0, 0);
    digitalWrite(pin1, 1);
    state = 2;
}

void shiniDCMotor::reverse(){
    digitalWrite(pin0, 1);
    digitalWrite(pin1, 0);
    state = 3;
}

void shiniDCMotor::setDuty(uint16_t _duty){
    
    #if defined(ARDUINO_ARCH_ESP32)  //use hardware PWM if ESP32
        ledcWrite( dutyPin, _duty);
    #else //or use standard Arduino libraries
        analogWrite( dutyPin, _duty);
        
    #endif
    duty = _duty;
}

uint16_t shiniDCMotor::getDuty(){
  return duty;
}

uint8_t shiniDCMotor::getState(){
  return state;
}
