#include <IRremote.h>

IRrecv myone(8);
decode_results myresult;

int bright = 0;
// + FFA857 - FFE01F

void setup() {
  myone.enableIRIn();
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(myone.decode(&myresult)){
    Serial.println(myresult.value, HEX);
    
    switch(myresult.value){
      case 0xFF30CF: digitalWrite(7, HIGH); break;
      case 0xFF18E7: digitalWrite(7, LOW); break;
      case 0xFF7A85: digitalWrite(6, HIGH); break;
      case 0xFF10EF: digitalWrite(6, LOW); break;
      case 0xFF38C7: digitalWrite(2, HIGH); break;
      case 0xFF5AA5: digitalWrite(2, LOW); break;
    }
    myone.resume();
  }

  delay(300);
}