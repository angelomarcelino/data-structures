/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo mDir, mEsq;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val = 0;    // variable to read the value from the analog pin

void setup() {
  Serial.begin(9600);
  mDir.attach(10);  // attaches the servo on pin 9 to the servo object
  mEsq.attach(11);
}

void loop() {
     // scale it to use it with the servo (value between 0 and 180)
  mDir.write(val);
  mEsq.write(val+4);
  delay(150);
  Serial.print(val);
  Serial.print(":");
  Serial.println(val+4);
  if(val<180) val++;
  else val = 0;
}

