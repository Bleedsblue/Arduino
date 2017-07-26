#ifndef SG
#define SG

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <String.h>
#include "LCD_and_Keypad.h"

class LCDScreen   {
  public:
    LCDScreen( bool takesInput = false); // Constructor. By default, A screen does not have an input.
    
    void printScreen();
    void screenInput ();
    void screenMessage (String newMessage);
    void updateVal( float newSensorVal);   

  private:
    const int MAX_LENGTH = 10;
    int userInput = 0;
    String message = " Hello, World! ";
    float sensorVal = 0;
    
    int inputString(char* buf);
  
};
#endif

