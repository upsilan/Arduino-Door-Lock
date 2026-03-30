const int numberOfInterrupts = 2;
int interrupts[numberOfInterrupts] = {2, 3};

void sleepSetup()
{
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
}

void startSleep()
{
  for(int i = 0; i < numberOfInterrupts; i++)
  {
    attachInterrupt(digitalPinToInterrupt(interrupts[i]), wakeUp, FALLING);
  }
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
}

void wakeUp()
{
  for(int i = 0; i < numberOfInterrupts; i++)
  {
    detachInterrupt(interrupts[i]);
  }
  
}