void setup() {
  pinMode(7, INPUT);

  Serial.begin(9600);
}

void loop() {
  int value = digitalRead(7);

  if(value){
    Serial.println("no magnet! :(");
    delay(1000);
  } else{
    Serial.println("magnet! :O");
    delay(1000);
  }
}
