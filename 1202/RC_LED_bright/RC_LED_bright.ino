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
    if(myresult.value == 0xFFA857){
      bright += 50;
      if(bright > 255) bright = 255;
      Serial.println(bright);
      analogWrite(6, bright);
    } else if(myresult.value == 0xFFE01F){
      bright -= 50;
      if(bright < 0) bright = 0;
      Serial.println(bright);
      analogWrite(6, bright);
    }
    myone.resume();
  }

  delay(300);
}