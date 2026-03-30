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
#include <LowPower.h>

SoftwareSerial mySerial(6, 7);

void setup()
{
  Serial.begin(9600);
  buzzerSetup();

  fingerprintSetup();
  keypadSetup();
  sleepSetup();
}

void loop()
{
  startSleep();
  //will sleep until interrupt
  wakeUp();
  unsigned long TimeSinceWakeup = millis();
  while(millis() - TimeSinceWakeup < 30000)
  {
    Serial.println("awake!");
  }
  //this will loop back and sleep until woken up again
}