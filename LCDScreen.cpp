#include "LCDScreen.h"
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <String.h>
  

LCDScreen::LCDScreen(bool takesInput){
  

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                         Print Screen:
//`Prints the message, sensor value, and input value (if it has one) of the appropriate screen
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  void LCDScreen::printScreen(String & message, float & sensorVal, float & userInput){
    message = _message;
    sensorVal = _sensorVal;
    userInput = _userInput;
  } //printScreen()

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                         Screen Input:
//      Allows the user to input a value to be stored via the keypad. Calls inputString()
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  void LCDScreen::inputScreen (float userInput){
    _userInput = userInput;
} //screenInput()


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                         Screen Message:
//      The user passes a string with a new message for a screens message to be set to.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void LCDScreen::updateMessage (String newMessage){
  _message = newMessage;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                         Update Value:
//      The user passes a float with a new message for a screens message to be set to.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void LCDScreen::updateVal( float newSensorVal){
  _sensorVal = newSensorVal;
}


