//this is the arduino project i made for my door lock

//fingerprint module
//red = vcc
//yellow = tx
//white = rx
//black = ground
//blue tch (interrupt)
//green vid (like vcc but only for interrupt)

#include <Wire.h>
#include <SoftwareSerial.h>
#include <Adafruit_Fingerprint.h>
#include <LowPower.h>

SoftwareSerial mySerial(6, 7);

unsigned long timeSinceWakeup;
bool breakLoop = false;
char input_kp[4] = {};
int index = 0;

void setup()
{
  Serial.begin(9600);
  buzzerSetup();

  fingerprintSetup();
  keypadSetup();
  sleepSetup();

  Serial.println("Initializing...");
  delay(1000);
}

void loop()
{
  startSleep();
  //will sleep until interrupt
  wakeUp();
  Serial.println("awake!");
  timeSinceWakeup = millis();

  while(millis() - timeSinceWakeup < 3000 && !breakLoop)
  {
    //check fingerprint
    if(isFingerTouching())   //doesn't exist yet
    {
      if(isValidFinger())  //doesn't exist yet
      {
        //open door
        delay(10000);
        //close door
        delay(100);
        breakLoop = true;
      }
    }
    else //not really necessary but i don't want you to be able to both input finger and also keypad, idk
    {
      keypadLogic();
    }
  }
  Serial.println("sleeping again");
  delay(50); //small delay so the text can print and just in general finish stuff up
  //this will loop back and sleep until woken up again
}

void keypadLogic()
{
  //check keypad
  //this is a nightmare of a state machine and i hate it so much and it also includes the fingerprint in it and fuck that since i want you to be able to press a button and then decide actually no
  // fingerprint but if i make it like this it makes it a bit hellish
  char temp = runningZero();   // this line may not work as of now, will check when keypad will arrive from aliexpress
  if (temp == ' ') { return; }
  switch(temp)
  {
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '0':
      input_kp[index] = temp;
      index++;
      //later add password logic when password is full and ready to guess (make it when index is 5 because password can be '', '', '', '') TODO
      break;
    case '*':
      for(int i = 0; i < 4; i++)
      {
        input_kp[i] = ' ';
      }
      index = 0;
      break;
    case '#':
      //put a function in here that goes like, if 1 2 8 or 9 good otherwise return
      //and then if it is good then do the func and also return or smth, idk i am tired
      break; 
    default:
      Serial.println("how did you even get here?");
      break;
  }
}