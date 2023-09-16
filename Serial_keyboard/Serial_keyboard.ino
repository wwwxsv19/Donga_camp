void setup(){

  pinMode(11, OUTPUT);

  Serial.begin(9600);

}

void loop(){
  if(Serial.available()){
    char ch = Serial.read();
    Serial.println(ch);

    if(ch == 'a'){
      digitalWrite(11, HIGH);
    }
    else{
      digitalWrite(11, LOW);
    }
  }
}