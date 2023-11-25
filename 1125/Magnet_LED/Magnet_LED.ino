int flag = 0;

void setup() {
  pinMode(7, INPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int value = digitalRead(7);

  if(!value){
    if(flag){
      digitalWrite(8, LOW);
      flag = 0;
      delay(500);
    } else{
      digitalWrite(8, HIGH);
      flag = 1;
      delay(500);
    }
  }
}
