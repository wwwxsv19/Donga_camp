int num[10][7] = {
  {0, 0, 0, 0, 0, 0, 1}, // 0
  {1, 0, 0, 1, 1, 1, 1}, // 1
  {0, 0, 1, 0, 0, 1, 0}, // 2
  {0, 0, 0, 0, 1, 1, 0}, // 3
  {1, 0, 0, 1, 1, 0, 0}, // 4
  {0, 1, 0, 0, 1, 0, 0}, // 5
  {0, 1, 0, 0, 0, 0, 0}, // 6
  {0, 0, 0, 1, 1, 1, 1}, // 7
  {0, 0, 0, 0, 0, 0, 0}, // 8
  {0, 0, 0, 0, 1, 0, 0} // 9
};

int led[7] = {2, 3, 4, 5, 6, 7, 8};

void setup() {
  for(int i=0; i<7; i++){
    pinMode(led[i], OUTPUT);
  }
  pinMode(12, INPUT);
}

void loop() {
  int value = digitalRead(12);

  if(value == HIGH){
    int n = random(0, 10);
    for(int i=0; i<7; i++){
      digitalWrite(led[i], num[n][i]);
    }
    delay(300);
  }
}