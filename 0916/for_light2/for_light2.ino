void setup(){
  pinMode(11, OUTPUT);
}

void loop(){
  digitalWrite(11, HIGH);
  for(int i=254; i>=0; i-=2){
    analogWrite(11, i);
    delay(50);
  }
}