#include <Servo.h>
Servo myone;

void setup() {
  myone.attach(9);
  pinMode(7, INPUT);
  Serial.begin(9600);
}

void loop() {
  int value = digitalRead(7);
  Serial.println(value);

  if(value) myone.write(90);
  else myone.write(0);
  
  delay(1000);
}