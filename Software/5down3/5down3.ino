/*
Single Supply Logic Level COnverter Hook-Up Guide

This project will beep continuosly with a frequency proportional 
to distance. A objects get closer the beep gets faster. 

Hardware:
 HC-SR04 Ultrasonic Sensor 
 SparkFun Pro Micro 3.3V
 SparkFun Single Supply Logic Level Converter
 Speaker

*/


#define trigPin 10
#define echoPin 16
#define Beep 3

void setup() {
  Serial.begin (4800);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(Beep, OUTPUT);
}

void loop() {
  long duration;
  long distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  //Pulse Trig Pin high for 10uS
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  //obtain the length of time the Echo Pin was high
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(1000);
}
