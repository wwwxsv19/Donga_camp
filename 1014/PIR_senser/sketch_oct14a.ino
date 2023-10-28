void setup() {
  pinMode(6, INPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int value = digitalRead(6);

  Serial.println(value);

  digitalWrite(2, value); // 굳이 if문 안 써도 돼용 ~~
}
