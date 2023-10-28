void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    int r = Serial.parseInt();
    int g = Serial.parseInt();
    int b = Serial.parseInt();

    if(Serial.read()=='\n'){
      analogWrite(11, r);
      analogWrite(10, g);
      analogWrite(9, b);
    }
  }
}