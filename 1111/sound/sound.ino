int flag = 0;

void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  int value = digitalRead(8);
  Serial.println(value);
  if(value){
    if(flag){
      digitalWrite(6, LOW);
      flag = !flag;
    } else{
      digitalWrite(6, HIGH);
      flag = !flag;
    }
  }
  delay(1000);
}