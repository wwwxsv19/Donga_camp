void setup() {
  pinMode(7, INPUT); // Echo
  pinMode(8, OUTPUT); // Trig
  Serial.begin(9600);
}

void loop() {
  digitalWrite(8, HIGH);
  delayMicroseconds(10);
  digitalWrite(8, LOW);

  long times = pulseIn(7, HIGH); // 마이크로 단위의 시간을 받는다!!

  int distance = ((340 * times) / 10000) / 2;
  /*
  마이크로 단위의 시간을 초로 바꾸고, 이는 미터 단위이므로 센치미터로 바꾼 후, 
  왔다갔다 중복 거리를 없애준다!
  */

  Serial.print(distance);
  Serial.println("cm");
  delay(100);
}