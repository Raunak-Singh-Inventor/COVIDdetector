void setup() 
{
//initialize serial communications at a 9600 baud rate
Serial.begin(9600);
}

void loop()
{
// send fake data through serial
Serial.print("Raunak");
Serial.print(",");
Serial.print(78);
Serial.println("");
//wait 100 milliseconds so we don't drive ourselves crazy
delay(100);
}
