#include <Wire.h>
int led = 23;
void setup(){
 pinMode(led, OUTPUT);
 Wire.begin(1); // join i2c bus with address #4
 Wire.onReceive(receiveEvent); // register event
 Serial.begin(9600); // start serial for output
}

void loop(){
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
 while(1 < Wire.available()){ // loop through all but the last
 char c = Wire.read(); // receive byte as a character
 Serial.print(c); // print the character
 }
 
 int x = Wire.read(); // receive byte as an integer
 Serial.println(x); // print the integer
 if(x==101){
 digitalWrite(led, HIGH);
 } else {
 digitalWrite(led, LOW);
 }
}
