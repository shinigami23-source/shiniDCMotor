
#include <Arduino.h>
#include <shiniDCMotor.h>


#define P0 26 //brown
#define P1 25  //white
#define DUTY 33 //blue


shiniDCMotor testMoter;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
testMotor.begin(P0 ,P1 ,DUTY, 10000, 8);
testMotor.setDuty(230);
}

void loop() {
  // put your main code here, to run repeatedly:
 testMotor.forward();                                                                                                                                                                                                                                                                                                                      ,
  erial.println("Front");
  delay(1000);
   testMotor.reverse();
  Serial.println("Back");
delay(1000);

}
