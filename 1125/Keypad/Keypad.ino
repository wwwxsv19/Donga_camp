#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char myKeyMap[ROWS][COLS] = {
  {'1', '2', '3', ' '},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '='},
  {'*', '0', '+', '\n'}
};

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {6, 7, 8, 9};

Keypad MKP = Keypad(makeKeymap(myKeyMap), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char value = MKP.getKey();
  if(value){
    Serial.print(value);
  }
}
