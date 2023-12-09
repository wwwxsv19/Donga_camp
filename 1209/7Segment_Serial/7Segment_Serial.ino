int number[4] = {};
String str[4] = {};

int com[4] = {9, 10, 11, 12};
int led[7] = {2, 3, 4, 5, 6, 7, 8};
int num[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 1, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  for(int i=0; i<4; i++){
    pinMode(com[i], OUTPUT);
  }
  for(int i=0; i<7; i++){
    pinMode(led[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    String value = Serial.readStringUntil("\n");
    Serial.println(value);
    for(int i=0; i<4; i++){
      str[i] = value.substring(i, i+1);
      number[i] = str[i].toInt();
    }
  }
  
  for(int i=0; i<4; i++){
    showNum(i, number[i]);
  }
}

void showNum(int c, int n){
  for(int i=0; i<4; i++){
    if(i == c) digitalWrite(com[i], LOW);
    else digitalWrite(com[i], HIGH);
  }
  for(int i=0; i<7; i++){
    digitalWrite(led[i], num[n][i]);
  }
  delay(2);
}