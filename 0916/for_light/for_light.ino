void setup(){
  pinMode(11, OUTPUT);

}

void loop(){
  digitalWrite(11, LOW);
  for(int i=1; i<256; i+=2){
    analogWrite(11, i);
    delay(50);
  }
}