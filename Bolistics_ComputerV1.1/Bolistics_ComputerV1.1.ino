
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <String.h>
#include "LCDScreen.h"
#include "LCD_and_Keypad.h"


void setupDisplay(){
  lcd.clear();
  lcd.print("Balistics  V1.1");
  lcd.setCursor(0,1);
  lcd.print("Computer");
  delay(2000);
}

void setup() {
  const int NUM_SCREENS = 10;
setupDisplay();

LCDScreen Screen[NUM_SCREENS]{{false},{true},{true},{true},{true},{true},{true},{true},{true},{true}};
Screen[0].printScreen();
}

void loop() {


}
