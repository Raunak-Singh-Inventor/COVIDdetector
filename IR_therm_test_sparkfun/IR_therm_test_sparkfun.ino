// Measure temp with MLX90614 and Sparkfun library
// written by raunak singh
#include <Wire.h> // Include Wire.h - Arduino I2C library
#include <SparkFunMLX90614.h> // Include IR thermometer library

IRTherm temp; // Create an IRTherm object called temp

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  temp.begin(); // Initialize I2C library and the MLX90614
  temp.setUnit(TEMP_F); // Set units to Farenheit (alternatively TEMP_C or TEMP_K)

}

void loop() {
  // put your main code here, to run repeatedly:
  // If the read is successful:
  float ambientT = temp.ambient(); // Get updated ambient temperature
  float objectT = temp.object(); // Get updated object temperature
  Serial.println("Ambient: " + String(ambientT));
  Serial.println("Object: " + String(objectT));
  Serial.println();
  
}
