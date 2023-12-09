int Row[9] = {-1, 13, 8, A3, 10, 5, A2, 4, A0};
int Col[9] = {-1, 9, 3, 2, 12, A1, 11, 7, 6};

void setup() {
  for(int i=2; i<=17; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  digitalWrite(Row[1], HIGH);
  delay(500);
  digitalWrite(Row[1], LOW);
  delay(500);
}