int light = 0;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  int value = analogRead(A0);
  Serial.println(value);
  if(value > 550){
    light += 120;
    if(light > 240) light = 0;
    analogWrite(6, light);
    delay(1000);
  }
}