const int rows[] = {}; //set this later
const int r = sizeof(rows);
const int cols[] = {}; //set this later
const int c = sizeof(cols);


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

char runningZero()
{

  unsigned long lastDebounceTime = 0;
  const unsigned long debounceDelay = 30; //in milliseconds
  char lastReading = ' ';
  char currentReading = ' ';

  const char keypad[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
  };
  //reset all the outputs to high (undistinguishable)
  for(int i = 0; i < 4; i++)
  {
    digitalWrite(rows[i], HIGH);
  }

  
  //for each input
  for(int i = 0; i < 4; i++)
  {
    //turn on all outputs and try to see if anything is down
    for(int j = 0; j < 4; j++)
    {
      //get the output working
      digitalWrite(rows[j], LOW);
      if(digitalRead(cols[i]) == LOW)
      {
        digitalWrite(rows[j], HIGH);
        currentReading = keypad[i][j];
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
      return currentReading;
    }
  }
  lastReading = currentReading;
  return ' ';
}