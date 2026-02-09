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

const int buzzer = 9;
const int buzzerNegative = 7;
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

void allow()
{
  tone(buzzer, 440, 750);
}

void wrong()
{
  for(int i = 0; i < 3; i++)
  {
    tone(buzzer, 440, 100);
    delay(50);
  }
}

void tone(int pin, int pitch, int timeMilliseconds)
{
  tone(pin, pitch);
  delay(timeMilliseconds);
  noTone(pin);
}
