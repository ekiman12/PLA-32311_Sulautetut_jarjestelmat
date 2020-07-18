void setup() {
  pinMode(13,OUTPUT); // NodeMCU
  Serial.begin(9600);
  
}

void loop() {
  digitalWrite(13,HIGH);  // Led On
  delay(1000);
  Serial.write("blink");
  digitalWrite(13,LOW); // Led Off
  delay(1000);

}
