void setup(){
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop(){
  digitalWrite(11, HIGH);
  digitalWrite(10, 100);
  digitalWrite(9, 10);
}