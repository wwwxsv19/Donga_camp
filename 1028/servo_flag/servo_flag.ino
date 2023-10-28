#include <Servo.h>
Servo myone;

int flag = 0;

void setup() {
  myone.attach(9);
  pinMode(12, INPUT);
  Serial.begin(9600);
}

void loop() {
  int value = digitalRead(12);
  Serial.println(value);

  if(value){
    if(flag) myone.write(0);
    else myone.write(90);
    
    flag = !flag;
  }

  delay(500);
}