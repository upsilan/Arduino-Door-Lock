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

  Serial.begin(9600);
  buzzerSetup();

  fingerprintSetup();
  keypadSetup();
}

void loop()
{
  runningZero();
  //sleep until interrupt
  //if interrupt came from keypad (possible shortcut if you know what pin interrupted it so you don't have to 0 run everything?)
  //do keypad logic
  //else if interrupt came from fingerprint sensor scan fingerprint
  //get fingerprint
}