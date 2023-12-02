#include <IRremote.h>

IRrecv myone(7);
decode_results myresult;

void setup() {
  myone.enableIRIn();
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(myone.decode(&myresult)){
    Serial.println(myresult.value, HEX);
    
    if(myresult.value == 0xFF30CF){
      digitalWrite(6, HIGH);
    } else{
      digitalWrite(6, LOW);
    }
    myone.resume();
  }
  delay(300);
}