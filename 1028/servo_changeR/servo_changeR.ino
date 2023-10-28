#include <Servo.h>
Servo myone;

void setup() {
  myone.attach(9);
  myone.write(0);
  pinMode(A0, INPUT);

  Serial.begin(9600);
}

void loop() {
  int value = analogRead(A0);
  int mapValue = map(value, 0, 1023, 0, 180);

  myone.write(mapValue);

  Serial.print(value); Serial.print(">>"); Serial.println(mapValue);

  delay(10);
}