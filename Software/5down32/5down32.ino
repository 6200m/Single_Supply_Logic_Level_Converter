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


#define TRIG_PIN 10
#define ECHO_PIN 16
#define Beep 3

void setup() {
  Serial.begin (9600);
  pinMode(TRIG_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  pinMode(Beep, OUTPUT);
}

void loop() {
  unsigned long t1;
  unsigned long t2;
  unsigned long pulse_width;
  float cm1;


  // Hold the trigger pin high for at least 10 us
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Wait for pulse on echo pin
  while (digitalRead(ECHO_PIN) == 0 );

  // Measure how long the echo pin was held high (pulse width)
  // Note: the micros() counter will overflow after ~70 min
  t1 = micros();
  while (digitalRead(ECHO_PIN) == 1);
  t2 = micros();
  pulse_width = t2 - t1;

  // Calculate distance in centimeters.
  cm1 = pulse_width*0.034/2;
  if (cm1 >= 200 || cm1 <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(cm1);
    Serial.println(" cm");

    tone(Beep,528); 
    delay(100);
    noTone(Beep);
    delay(cm1);
    

  }
}
