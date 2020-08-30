// define Pins
int gLedPin=6;
int yLedPin=7;
int tempPin=A1;    // temperature sensor value
int rangeEPin=9;  // distance sensor echo
int rangeTPin=8; // distanse sensor trigger
int noiseLPin=A0; // volume sensor level

//define variables
String command = "";
int reading = 0;
float output = 0;
bool AlarmOn = false;
float curDist = 0;
float lastDist = 0;
int duration = 0;

// measure distance in cm
float getDistance(){
  // Clears the trigger
  digitalWrite(rangeTPin, LOW);
  delayMicroseconds(2);
  
  // Sets the rangeTPin on HIGH state for 10 micro seconds
  digitalWrite(rangeTPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(rangeTPin, LOW);
  
  // Reads the rangeEPin, returns the sound wave travel time in microseconds
  duration = pulseIn(rangeEPin, HIGH);
  
  // Calculating the distance (assuming regular speed of sound in air)
  return duration*0.034/2;   
}



void setup() { 
  // set outputs
  pinMode(gLedPin, OUTPUT);
  pinMode(yLedPin, OUTPUT);
  pinMode(rangeTPin, OUTPUT);

  // set inputs
  pinMode(tempPin, INPUT);
  pinMode(rangeEPin, INPUT);
  pinMode(noiseLPin, INPUT);


    
  if (Serial){
    Serial.begin(9600);
    digitalWrite(gLedPin, HIGH);
  }

}

void loop() {
  command = Serial.readString();
  command.trim();
  //Serial.print(command); // Debugging aid

  // yellow led related commands
  if (command=="LedStatus"){
    if (digitalRead(yLedPin) == HIGH){
      Serial.println("LedOn");
    } else {
      Serial.println("LedOff");
    }
       
  } else if (command.equals("LedOn")){
    digitalWrite(yLedPin, HIGH);
    Serial.println("AyeAye");
    
  } else if (command.equals("LedOff")){
    digitalWrite(yLedPin, LOW);
    Serial.println("AyeAye");
    
  } // Getting sensor statuses
    else if (command.equals("Temp")) {
      reading = analogRead(tempPin);
      output = 5.0*reading/1023.0*100.0; // 5 volt arduino sensor with voltageoutput of 10mV/C
      Serial.println(output);
      
  } else if (command.equals("Noise")) {
      reading = analogRead(noiseLPin);
      output = reading/1023.0*100.0; // returns a percentage of sensor range
      Serial.println(output);
      
  } // setting up alarms
    else if (command.equals("AlarmSet")){
      AlarmOn = true;
      lastDist = getDistance(); // for alarm function
      Serial.println("AyeAye");
      
  } else if (command.equals("AlarmReset")){
      AlarmOn = false;
      Serial.println("AyeAye");
      
  } // echoing
    else if (command.equals("Echo")){
      Serial.println("ExcuseMe?");
  }

  // Alarm functionality
  if (AlarmOn){
    curDist = getDistance();
    if (abs(curDist-lastDist)>15){
      Serial.println("Alarm!");
    }
  }

}
