int arr[8] = {262, 294, 330, 350, 392, 440, 494, 523};
int pin[8] = {6, 7, 8, 9, 10, 11, 12, 13};

void setup(){
  pinMode(1, OUTPUT);
  for(int i=0; i<8; i++){
    pinMode(pin[i], INPUT);
  }
}

void loop(){
  for(int i=0; i<8; i++){
    if(digitalRead(pin[i])){
      tone(2, arr[i]);
      delay(300);
      noTone(2);
    }
  }
}