/*
* Non-contact Thermometer with GY - 906 module
* Support for the MLX90614 sensor on the I2C bus
* SDA line = A4
* SCL line = A5
* Sensor supply with 5V
*/


#include <i2cmaster.h>
#include <LiquidCrystal.h>


LiquidCrystal lcd (8, 9, 4, 5, 6, 7);

int address = 0xb4; // Sensor address MLX90614
int erc = 0; // Variable holding the PEC value
int dataH = 0; // The second byte of data
int dataL = 0; // The first byte of data
double tempnalsb = 0.02; // Variable by which the digital value will be multiplied
double temperature = 0; // Variable holding the temperature
    
    
void setup () {
  i2c_init (); // Initialization of the I2C bus
  lcd.begin (16, 2); // Initialize the display
  
  
}




void loop () {
 
  i2c_start_wait (address + I2C_WRITE); // Start I2C communication in write mode
  i2c_write (0x07); // Write the value 0x07 (select the register Tobj1)
  i2c_rep_start (address + I2C_READ); // Restart I2C communication at the read address
  dataL = i2c_readAck (); // Read the first byte of data
  dataH = i2c_readAck (); // Read the second byte of data
  erc = i2c_readNak (); // Read the third (unimportant) data byte
  i2c_stop (); // End of I2C transmission
  
  
  temperature = (double) (((dataH & 0x007F) << 8) + dataL); // Create a 16-bit variable consisting of two one-byte variables
  temperature = temperature * tempnalsb; // For one bit 0.02 K, the result of this operation is the temperature in Kelvin
  
  temperature = temperature - 273.15; // Conversion to Celsius degrees
  
  lcd.setCursor (0,0); // Display (first LCD line)
  lcd.print ("Object =");
  lcd.print (temperature);
  lcd.print ("");
  lcd.write (0xDF); // Degree sign
  lcd.print ("C");
  
  i2c_start_wait (address + I2C_WRITE);
  i2c_write (0x06); // Select the ambient temperature register
  i2c_rep_start (address + I2C_READ);
  dataL = i2c_readAck ();
  dataH = i2c_readAck ();
  erc = i2c_readNak ();
  i2c_stop ();
  
  
  temperature = (double) (((dataH & 0x007F) << 8) + dataL);
  temperature = temperature * tempnalsb;
  temperature = temperature - 273.15;
   
  lcd.setCursor(0,1); // Display (second LCD line)
  lcd.print ("Ambient =");
  Serial.print (temperature);
  lcd.print ("");
  lcd.write (0xDF);
  lcd.print ("C");

delay (200); // Delay 200ms
}
