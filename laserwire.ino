#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 9);
int sensorPin = A0; // select the input pin for the potentiometer
int sensorValue = 0;
int command = 1;
int alarm = 7; // variable to store the value coming from the sensor
void setup() {
  Serial.begin(9600);
  pinMode (alarm, OUTPUT);
}
void loop() {
  sensorValue = analogRead(sensorPin);
  delay(3000);
  Serial.println(sensorValue, DEC);
  if (sensorValue > 100){
    digitalWrite (alarm, HIGH); 
  }
  else{
    digitalWrite (alarm, LOW); 
  }

  if (sensorValue > 100 && mySerial.available()){
    Serial.write(command);
    mySerial.write(command);
  }
}
