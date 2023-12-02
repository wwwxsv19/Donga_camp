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
}

void loop() {
  for(int i=0; i<10; i++){
    for(int j=0; j<7; j++){
      digitalWrite(led[j], num[i][j]);
    }
    delay(500);
  } 
}