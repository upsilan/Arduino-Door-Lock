const int buzzer = 4;
const int buzzerNegative = 5;

void buzzerSetup()
{
  pinMode(buzzerNegative, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzerNegative, LOW);
}

void accessGranted()
{
  //A chord
  tone(440, 250); //A
  tone(550, 255); //A * 5/4 (major third)
  tone(660, 255); //C# * 6/5 (minor third)
  tone(880, 255); //C# * 4/3 (perfect fourth) 
}

void wrong()
{
  for(int i = 0; i < 3; i++)
  {
    tone(220, 100);
    delay(50);
  }
}

void codeMode()
{
  tone(440, 400);
}

void fingerprintMode()
{
  for(int i = 0; i < 2; i++)
  {
    tone(440, 400);
    delay(50);
  }
}

void fingerprintRemovalMode()
{
  for(int i = 0; i < 3; i++)
  {
    tone(440, 250);
    delay(50);
  }
}

void fingerprintErraseMode()
{
  for(int i = 0; i < 5; i++)
  {
    tone(440, 250);
    delay(50);
  }
}

void tone(int pitch, int timeMilliseconds)
{
  tone(buzzer, pitch);
  delay(timeMilliseconds);
  noTone(buzzer);
}
