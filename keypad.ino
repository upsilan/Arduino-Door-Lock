const int cols[] = {8, 7, 6};
const int c = 3;
const int rows[] = {12, 11, 10, 9};
const int r = 4;

char password[] = {'1', '2', '3', '4'};

void keypadSetup()
{
  for(int i = 0; i < c; i++)
  {
    pinMode(cols[i], INPUT_PULLUP);
  }
  for(int i = 0; i < r; i++)
  {
    pinMode(rows[i], OUTPUT);
    digitalWrite(rows[i], LOW);
  }
  Serial.println("finished keypad setup");
}

void changePassword(char newPass[4])
{
  for(int i = 0; i < 4; i++)
  {
    password[i] = newPass[i];
  }
}

bool authenticatePassword(char attempt[4])
{
  Serial.println(password);
  Serial.println(attempt);
  return password == attempt; //maybe would always return true since char[4] = char[4] if so make it return true if p[0] == a[0] && p[1] == a[1] etc etc
}

char runningZero()
{

  unsigned long lastDebounceTime = 0;
  const unsigned long debounceDelay = 30; //in milliseconds
  char lastReading = ' ';
  char currentReading = ' ';

  const char keypad[4][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}
  };
  //reset all the outputs to high (undistinguishable)
  for(int i = 0; i < r; i++)
  {
    digitalWrite(rows[i], HIGH);
  }

  
  //for each input
  for(int i = 0; i < c; i++)
  {
    //turn on all outputs and try to see if anything is down
    for(int j = 0; j < r; j++)
    {
      //get the output working
      digitalWrite(rows[j], LOW);
      if(digitalRead(cols[i]) == LOW)
      {
        digitalWrite(rows[j], HIGH);
        currentReading = keypad[j][i];
        Serial.println(currentReading);
      }
      //reset the output back
      digitalWrite(rows[j], HIGH);
    }
  }

  // If reading changed, reset timer
  if (currentReading != lastReading)
  {
    lastDebounceTime = millis();
  }

  // If stable for long enough
  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    if (currentReading != lastReading)
    {
      lastReading = currentReading;
      if(currentReading != ' ')
      {
        tone(440, 50);
        return currentReading;
      }
    }
  }
  lastReading = currentReading;
  return ' ';
}