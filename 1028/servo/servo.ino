#include <Servo.h>
Servo myone;

void setup() {
  myone.attach(9);
}

void loop() {
  int i=0;

  for( ; i<=180; i+=10){
    myone.write(i);
    delay(100);
  }
  for( ; i>=0; i-=10){
    myone.write(i);
    delay(100);
  }
}