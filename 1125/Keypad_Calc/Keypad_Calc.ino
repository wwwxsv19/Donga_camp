#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C mylcd(0x27, 16, 2);

const byte ROWS = 4;
const byte COLS = 4;

char myKeyMap[ROWS][COLS] = {
  {'1', '2', '3', 'C'},
  {'4', '5', '6', '='},
  {'7', '8', '9', '+'},
  {'*', '0', '/', '-'}
};

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {6, 7, 8, 9};

Keypad MKP = Keypad(makeKeymap(myKeyMap), rowPins, colPins, ROWS, COLS);

String input = "";

float num1, num2;
int flag = 0, cnt = 0;
char calc = "";

void setup() {
  Serial.begin(9600);
  mylcd.init();
  mylcd.backlight();
}

void loop() {
  char value = MKP.getKey();
  
  if(value){
    if(isdigit(value)){
      if(!flag){
        input += value;
        mylcd.setCursor(0, 0); mylcd.print(input);
        cnt++;
      } else{
        input += value;
        mylcd.setCursor(cnt, 0); mylcd.print(input);
      }
    } else if(value == '+' ||  value == '-' || value == '*' || value == '/'){
      num1 = input.toInt();
      mylcd.setCursor(cnt, 0); mylcd.print(value);
      calc = value; input = ""; cnt++; flag += 1;
    } else if(value == '='){
      num2 = input.toInt();
      mylcd.setCursor(0, 1);
      mylcd.print("=");
      switch(calc){
        case '+': mylcd.print(num1 + num2); break;
        case '-': mylcd.print(num1 - num2); break;
        case '*': mylcd.print(num1 * num2); break;
        case '/': mylcd.print(num1 / num2); break;
      }
    } else if(value == 'C'){
      mylcd.clear();
      value = ""; input = ""; calc = "";
      cnt = 0; flag = 0;
    }
  }
}
