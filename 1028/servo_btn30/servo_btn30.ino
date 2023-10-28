#include <Servo.h>
Servo myone;

int num = 0;

void setup() {
  myone.attach(9);
  pinMode(12, INPUT);
  Serial.begin(9600);
}

void loop() {
  int value = digitalRead(12);
  Serial.println(value);

  if(value){
    num += 30;
    if(num>180) num = 0;
  }
  myone.write(num);
  delay(100);
}