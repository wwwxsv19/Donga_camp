int flag = 0;

void setup() {
  pinMode(11, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  int value = digitalRead(2);

  if(value){
    if(!flag){
      digitalWrite(11, HIGH);
      delay(500);
      flag = 1;
    }
    else{
      digitalWrite(11, LOW);
      delay(500);
      flag = 0;
    }    
  }
}
