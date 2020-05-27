// Measure temp with MLX90614 and Adafruit library
// written by raunak singh
#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  Serial.begin(9600);

  Serial.println("Adafruit MLX90614 test");  

  mlx.begin();  
}

void loop() {
    Serial.print(mlx.readObjectTempF());
    Serial.println();
}