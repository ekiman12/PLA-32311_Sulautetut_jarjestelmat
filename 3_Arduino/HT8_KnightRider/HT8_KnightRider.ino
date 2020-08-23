int pos=0;  // running position
int dir=0;  // direction of movement
int MAX=12; // total number of leds
int ON=3;   // leds on at the same time

void setup() {
  for (int i=0; i<MAX;i++){
    pinMode(i,OUTPUT);
  }
  
}

void loop() {
    // flash movementi direction
  if (pos==0){
    dir=1;  // forward direction
  } else if (pos==MAX-ON) {
    dir=-1; // backward direction
  }

    // set lit and dark leds
  for (int i=0;i<MAX;i++){
    if (i<pos || i>=pos+ON){
      digitalWrite(i,LOW);
    } else {
      digitalWrite(i,HIGH);
    }
  }
  delay(150); // stripe movement speed
  
  pos=pos+dir;  // move iteration
}
