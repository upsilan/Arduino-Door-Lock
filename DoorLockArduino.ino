//this is the arduino project i made for my door lock
//buzzer (- 7) (+ 9)

//fingerprint module
//red = vcc
//yellow = tx
//white = rx
//black = ground

#include <Wire.h>
#include <SoftwareSerial.h>
#include <Adafruit_Fingerprint.h>

SoftwareSerial mySerial(2, 3);

void setup()
{
  pinMode(buzzerNegative, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzerNegative, LOW);

  Serial.begin(9600);

  fingerprintSetup();
}

void loop()
{
  
}