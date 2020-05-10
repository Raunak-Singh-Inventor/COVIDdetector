#include <Keypad.h>
#include <LiquidCrystal.h>

char * p_arr = new char[2];
String * p_names = new String[4];
char *pins= new char[4];





// LCD intialization code
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// keypad intialization code
const byte ROWS = 3;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '4', '7', '*'},
  {'2', '5', '8', '0'},
  {'3', '6', '9', '#'}
};

byte rowPins[ROWS] = {36, 34, 32};
byte colPins[COLS] = {30, 28, 26, 24};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Enter No:");
  pins[0]= '1';
  pins[1]= '2';
  pins[2]= '3';
  pins[3]= '4';  
  p_names[0] ="Raunak";
  p_names[1] ="Jasmeen";
  p_names[2] ="Mandeep";
  p_names[3] ="Pyara";
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = customKeypad.getKey();
  if (key) {
    if (key!='#') {
      lcd.print(key);
      p_arr[0] = key;
    }
    if (key == '#') {
      p_arr[1] = key;
      lcd.clear();
      lcd.print("checking...");
      for (int i=0;i<4;i++) {
        if (pins[i] == p_arr[0]) {
          lcd.clear();
          lcd.print(p_names[i]);
          Serial.print(p_names[i]);
          delay(300);
          break;
        }
        else {
          lcd.clear();
          lcd.print("Access denied");
        }
      }
    }
    if (key == '*') {
      lcd.clear();
      lcd.print("Enter No:");
    }
  }
}
