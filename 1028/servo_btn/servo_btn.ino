#include <Servo.h>
Servo myone;

void setup() {
  myone.attach(9);
  pinMode(12, INPUT);
  Serial.begin(9600);
}

void loop() {
  int value = digitalRead(12);
  Serial.println(value);

  if(value) myone.write(90);
  else myone.write(0);
}