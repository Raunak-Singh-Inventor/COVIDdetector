// Measure temp with MLX90614 and Adafruit library
// written by raunak singh

// install libraries
//  before importing
#include <Wire.h>
#include <Adafruit_MLX90614.h>

// define button pin
int button = 2;

// define sensor
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  Serial.begin(9600); // Begin Serial
  mlx.begin();  // begin sensor
  pinMode(button,INPUT_PULLUP);
}

void loop() {
  // read object temp
    if(digitalRead(button) == LOW) {
      Serial.print(mlx.readObjectTempF());
      Serial.println();
    }
    delay(1000);

}
