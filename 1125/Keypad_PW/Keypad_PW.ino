#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char myKeyMap[ROWS][COLS] = {
  {'1', '2', '3', ' '},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '='},
  {'*', '0', '+', '!'}
};

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {6, 7, 8, 9};

Keypad MKP = Keypad(makeKeymap(myKeyMap), rowPins, colPins, ROWS, COLS);

String password = "8465!!";
String InputPW = "";

int count = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  char value = MKP.getKey();
  
  if(value){
    Serial.print(value);
    InputPW += value;
    count++;
  }

  if(count == 6){
    count = 0;
    Serial.println();
    delay(300);
    if(password == InputPW){
      Serial.println("welcome!");
    } else{
      Serial.println("Go away!!");
    }
    InputPW = "";
  }
}
