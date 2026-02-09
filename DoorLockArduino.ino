//this is the arduino project i made for my door lock
//buzzer (- 7) (+ 9)

//fingerprint module
//red = vcc
//yellow = tx
//white = rx
//black = ground


const int buzzer = 9;
const int buzzerNegative = 7;

void setup()
{
  pinMode(buzzerNegative, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzerNegative, LOW);  
  delay(1000);
  allow();
  delay(3000);
  wrong();
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
