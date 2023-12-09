int Row[9] = {-1, 13, 8, A3, 10, 5, A2, 4, A0};
int Col[9] = {-1, 9, 3, 2, 12, A1, 11, 7, 6};

int heart[9][9] = {
  {-1, -1, -1, -1, -1, -1, -1, -1, -1},
  {-1, 0, 0, 0, 0, 0, 0, 0, 0},
  {-1, 0, 1, 1, 0, 0, 1, 1, 0},
  {-1, 1, 1, 1, 1, 1, 1, 1, 1},
  {-1, 1, 1, 1, 1, 1, 1, 1, 1},
  {-1, 0, 1, 1, 1, 1, 1, 1, 0},
  {-1, 0, 0, 1, 1, 1, 1, 0, 0},
  {-1, 0, 0, 0, 1, 1, 0, 0, 0},
  {-1, 0, 0, 0, 0, 0, 0, 0, 0}
};

int clearheart[9][9] = {
  {-1, -1, -1, -1, -1, -1, -1, -1, -1},
  {-1, 0, 0, 0, 0, 0, 0, 0, 0},
  {-1, 0, 1, 1, 0, 0, 1, 1, 0},
  {-1, 1, 0, 0, 1, 1, 0, 0, 1},
  {-1, 1, 0, 0, 0, 0, 0, 0, 1},
  {-1, 0, 1, 0, 0, 0, 0, 1, 0},
  {-1, 0, 0, 1, 0, 0, 1, 0, 0},
  {-1, 0, 0, 0, 1, 1, 0, 0, 0},
  {-1, 0, 0, 0, 0, 0, 0, 0, 0}
};

void setup() {
  for(int i=2; i<=17; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  makeClearHeart();
}

void clear(){
  for(int i=1; i<=8; i++){
    digitalWrite(Row[i], LOW);
    digitalWrite(Col[i], HIGH);
  }
}

void makeHeart(){
  for(int i=1; i<=8; i++){
    for(int j=1; j<=8; j++){
      if(heart[i][j] == 1){
        digitalWrite(Row[i], HIGH);
        digitalWrite(Col[j], LOW);
      } else{
        digitalWrite(Col[j], HIGH);
      }
    }
    clear();
  }
}

void makeClearHeart(){
  for(int i=1; i<=8; i++){
    for(int j=1; j<=8; j++){
      if(clearheart[i][j] == 1){
        digitalWrite(Row[i], HIGH);
        digitalWrite(Col[j], LOW);
      } else{
        digitalWrite(Col[j], HIGH);
      }
    }
    clear();
  }
}