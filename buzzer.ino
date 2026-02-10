const int buzzer = 9;
const int buzzerNegative = 7;

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
