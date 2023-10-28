int arr[8] = {262, 294, 330, 349, 392, 440, 493, 523};

void setup() {
  pinMode(11, OUTPUT);

}

void loop() {
  for(int i=0; i<8; i++){
    tone(11, arr[i]);
    delay(500);
  }
}
