// 전역 변수
int flag = 0; // 현재 led 상태가 어떤지

void setup() {
  pinMode(11, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  int value = digitalRead(2);
  if(value==HIGH){
    if(!flag){
      digitalWrite(11, HIGH);
      delay(50);
      flag = 1;
    }
    else{
      digitalWrite(11, LOW);
      delay(50);
      flag = 0;
    }
  }
}