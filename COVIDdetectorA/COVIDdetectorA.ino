//####################//
// Recieving hub of project
// Takes in input, store name and measure temperature
// by Raunak Singh
//####################//

// install two libraries from manager
//   before importing
#include <Keypad.h>
#include <LiquidCrystal.h>

char * p_arr = new char[2]; // create a new pointer array
String * p_names = new String[4]; // create a new pointer array for names
char *pins= new char[4]; // create a new pointer array for the pins or passcodes of the user

// LCD intialization code
//const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8; // define connected pins
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // define them in function
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

// keypad intialization code
const byte ROWS = 3; // specify columns
const byte COLS = 4; // specify rows

// alignment of keys
char hexaKeys[ROWS][COLS] = {
  {'1', '4', '7', '*'},
  {'2', '5', '8', '0'},
  {'3', '6', '9', '#'}
};

byte rowPins[ROWS] = {36, 34, 32}; // define pins
byte colPins[COLS] = {30, 28, 26, 24}; // define pins

// define keypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //  intialize Serial monitor
  lcd.begin(16,2); // begin LCD
  lcd.print("Enter No:"); // print ready to input screen on lcd
  pins[0]= '1'; // define pin for Raunak
  pins[1]= '2'; // define pin for Jasmeen
  pins[2]= '3'; // define pin for Mandeep
  pins[3]= '4'; // define pin for Pyara
  // challenge: try to edit the code to add your own name in!
  p_names[0] ="Raunak";
  p_names[1] ="Jasmeen";
  p_names[2] ="Mandeep";
  p_names[3] ="Pyara";
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = customKeypad.getKey(); // ready to grab input from user
  // if key is entered
  if (key) {
    // if key is not '#'
    if (key!='#') {
      lcd.print(key); // print key
      p_arr[0] = key; // add key to array to store
    }
    // if key  = is '#'
    if (key == '#') {
      p_arr[1] = key; // save hash char as second element 
      lcd.clear(); // clear lcd
      lcd.print("checking..."); // loading
      // start for loop
      for (int i=0;i<4;i++) {
        // check if any of the pins are equal to input
        if (pins[i] == p_arr[0]) {
          lcd.clear(); // clear lcd
          lcd.print(p_names[i]); // print the name corresponding to the specified pin
          Serial.println(p_names[i]); // also print it in Serial
          delay(300); // delay
          break; // break out of loop
        }
        else {
          lcd.clear(); // clear lcd
          lcd.print("Access denied"); // show pin not allowed
        }
      }
    }
    // if key is '*'
    if (key == '*') {
      lcd.clear(); // clear lcd
      lcd.print("Enter No:"); // reset to input
    }
  }
}

//___DONE___//
