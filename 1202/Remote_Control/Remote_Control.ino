#include <IRremote.h>

IRrecv myone(7);
decode_results myresult;

void setup() {
  myone.enableIRIn();
  Serial.begin(9600);
}

void loop() {
  if(myone.decode(&myresult)){
    Serial.println(myresult.value, HEX);
    myone.resume();
  }
  delay(300);
}