void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  int red = random(256);
  int blue = random(256);
  int green = random(256);

  analogWrite(11, red);
  analogWrite(10, green);
  analogWrite(9, blue);

  delay(1000);
}