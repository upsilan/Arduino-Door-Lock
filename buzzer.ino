const int buzzer = 4;
const int buzzerNegative = 5;

void buzzerSetup()
{
  pinMode(buzzerNegative, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzerNegative, LOW);
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

void tone(int pitch, int timeMilliseconds)
{
  tone(buzzer, pitch);
  delay(timeMilliseconds);
  noTone(buzzer);
}
