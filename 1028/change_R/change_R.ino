void setup() {
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(A0);
  
  Serial.print(value);

  // map 함수 : 변환할 값의 최솟값최댓값을 입력하면 원하는 범위의 최솟값최댓값으로 비례 변환
  int newValue = map(value, 0, 1023, 0, 255);
  
  analogWrite(9, newValue); // another way : analogWrite(9, value/4);
  
  Serial.print(">>");
  Serial.println(newValue);
}