void setup(){
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop(){
  light(8);
  light(10);
  light(11);
}

void light(int a){
  digitalWrite(a, HIGH);
  delay(500);
  digitalWrite(a, LOW);
}