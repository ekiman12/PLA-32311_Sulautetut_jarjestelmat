#include <Wire.h>
String arvo="0";
const int buttonPin = 2;
int buttonState = 0;
int sensorPin = 0;//lampotilaa varten
void setup(){
 pinMode(buttonPin, INPUT);
 Wire.begin(); // join i2c bus (address optional for master)
}

byte x = 0;

void loop(){
 int reading = analogRead(sensorPin);
 float voltage = reading * 5.0;
 voltage /= 1024.0;
 float temperatureC = voltage  * 100 ;
 buttonState = digitalRead(buttonPin);
 // check if the pushbutton is pressed.
 // if it is, the buttonState is HIGH:
 if (buttonState == HIGH) { 
 x=101;
 } else {
 //x=100;
 x=(int)(temperatureC);
 }
 
 Wire.beginTransmission(4); // transmit to device #4
 Wire.write("x is "); // sends five bytes
 Wire.write(x);
 Wire.endTransmission(); // stop transmitting
 delay(500);
}
