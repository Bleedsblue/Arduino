#include "LCDScreen.h"
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <String.h>
LiquidCrystal lcd(5, 4, 3, 2, 1, 0);

LCDScreen::LCDScreen(bool takesInput){
  
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                         Print Screen:
//`Prints the message, sensor value, and input value (if it has one) of the appropriate screen
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  void LCDScreen::printScreen(){
    lcd.clear();
    lcd.print(this->message);
    lcd.setCursor(0,1);
    lcd.print("Val: ");
    lcd.print(this->sensorVal);
    lcd.setCursor(6,1);
    lcd.print("Input: ");
    lcd.print(this->userInput); 
  } //printScreen()

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                         Screen Input:
//      Allows the user to input a value to be stored via the keypad. Calls inputString()
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  int LCDScreen::screenInput (){
    char inputChar[this->MAX_LENGTH];
    lcd.clear();
    lcd.print("Input: ");
    lcd.setCursor(7,0);
    if(inputString(inputChar)==0)
      this->userInput = 0;
    this->userInput = atoi(inputChar);
} //screenInput()

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                         Input String:
//      Called by screenInput() to process each key press while inputing a value, display 
//                   them, and return the number of characters entered.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int LCDScreen::inputString(char *buf){
  for(int i=0;i<this->MAX_LENGTH-1;i++){
    buf[i]=keypad.waitForKey();
    if(buf[i]=='#')
      break;
    lcd.print(buf[i]);
  }
  buf[i]=0;
  return i;
} //inputString()

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                         Screen Message:
//      The user passes a string with a new message for a screens message to be set to.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void LCDScreen::screenMessage (String newMessage){
  this->message = newMessage;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                         Update Value:
//      The user passes a float with a new message for a screens message to be set to.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void LCDScreen::updateVal( float newSensorVal){
  this->sensorVal = newSensorVal;
}


