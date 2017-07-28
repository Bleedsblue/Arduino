#ifndef SG
#define SG

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
#include <String.h>

class LCDScreen   {
  public:
    const int MAX_LENGTH = 10;
    bool takesInput;
    LCDScreen( bool takesInput = true);
    void printScreen(String & message, float & sensorVal, float & userInput);
    void inputScreen(float userInput);
    void updateMessage (String newMessage);
    void updateVal( float newSensorVal);   

  private:

    float _userInput = 0;
    String _message = " Hello, World! ";
    float _sensorVal = 0;  
};
#endif

