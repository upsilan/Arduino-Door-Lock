const int numberOfInterrupts = 2;
int interrupts[numberOfInterrupts] = {2, 3};

void sleepSetup()
{
  for(int i = 0; i < numberOfInterrupts; i++)
  {
    pinMode(interrupts[i], INPUT_PULLUP);
  }
}

void startSleep()
{
  noTone(buzzer);
  for(int i = 0; i < 4; i++)
  {
    input_kp[i] = ' ';
  }
  index = 0;
  for(int i = 0; i < numberOfInterrupts; i++)
  {
    attachInterrupt(digitalPinToInterrupt(interrupts[i]), wakeUp, RISING);
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