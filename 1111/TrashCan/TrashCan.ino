#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Servo myservo;
LiquidCrystal_I2C mylcd(0x27, 16, 2);

int melody[] = {262, 330, 392, 520};
int flag = 0;

void setup() {
  mylcd.init();
  mylcd.backlight();

  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(9, OUTPUT);

  myservo.attach(10);
  myservo.write(0);

  Serial.begin(9600);
}

void loop() {
  mylcd.setCursor(0, 0);

  digitalWrite(2, HIGH);
  delayMicroseconds(5);
  digitalWrite(2, LOW);

  long dur = pulseIn(3, HIGH);
  int distance = dur * 340 / 10000 / 2;
  
  Serial.println(distance);

  if(distance < 10){
    myservo.write(0);
    mylcd.print("WELCOME!^_^");
    delay(100);
    if(!flag) playHi();
    flag = 1;
  }
  else{
    myservo.write(90);
    mylcd.clear();
    if(flag) playBye();
    flag = 0;
  }

  delay(100);
}

void playHi(){
  for(int i=0; i<4; i++){
    tone(9, melody[i]);
    delay(150);
  }
  noTone(9);
}

void playBye(){
  for(int i=3; i>=0; i--){
    tone(9, melody[i]);
    delay(150);
  }
  noTone(9);
}