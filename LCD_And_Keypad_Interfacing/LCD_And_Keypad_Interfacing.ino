#include <LiquidCrystal.h>


#include <LiquidCrystal.h>
#include <Keypad.h>
#include <String.h>
#include "LCDScreen.h"


LiquidCrystal lcd(5, 4, 3, 2, 1, 0);
const byte COLS = 4;
const byte ROWS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {6,7,8,9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {10,11,12,13}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
//
//typedef struct{
//  String message;
//  float Val;
//  int Input;
//} screen;
//  screen screen1;
//  screen screen2;
//  screen screen3;
//  screen screen4;
//  screen currentScreen;
//
//void printScreen (screen screenToPrint){
//  lcd.clear();
//  lcd.print(screenToPrint.message);
//  lcd.setCursor(0,1);
//  lcd.print("Val: ");
//  lcd.print(screenToPrint.Val);
//  lcd.setCursor(6,1);
//  lcd.print("Input: ");
//  lcd.print(screenToPrint.Input);  
//}
//  
//screen chooseScreen (char key){
//  screen currentScreen;
//   
//   if( key == 'A'){
//    printScreen(screen1);
//    currentScreen = screen1;
//  }
//  else if ( key == 'B'){
//    printScreen(screen2);
//    currentScreen = screen2;
//  }
//  else if ( key == 'C'){
//    printScreen(screen3);
//    currentScreen = screen3;
//  }
//  else if ( key == 'D'){
//    printScreen(screen4);
//    currentScreen = screen4;
//  }
//  return currentScreen;
//}
//
//void processCommand (char key, screen currentScreen){
// if( key == 'A'){
//    printScreen(screen1);
//    currentScreen = screen1;
//  }
//  else if ( key == 'B'){
//    printScreen(screen2);
//    currentScreen = screen2;
//  }
//  else if ( key == 'C'){
//    printScreen(screen3);
//    currentScreen = screen3;
//  }
//  else if ( key == 'D'){
//    printScreen(screen4);
//    currentScreen = screen4;
//  }
//  else if ( key == '*'){
//    currentScreen.Input = screenInput();
//    printScreen(currentScreen);
//  }
//}
//
//int screenInput (){
//  char num2Input[10];
//  lcd.clear();
//  lcd.print("Input: ");
//  lcd.setCursor(7,0);
//  if(inputString(num2Input,10)==0)
//    return 0;
//    
//  return atoi(num2Input);
//}

//int inputString(char *buf, int maxlen)
//{
//  int i;
//
//  for(i=0;i<maxlen-1;i++)
//  {
//    buf[i]=keypad.waitForKey();
//    if(buf[i]=='#')
//      break;
//    lcd.print(buf[i]);
//  }
//  buf[i]=0;
//  return i;
//}

void setup() {
//
//    // set up the LCD's number of columns and rows:
//  lcd.begin(16, 2);
//  // Print a message to the LCD.
//  screen1.message = "Print Screen 1";
//  screen1.Val = 1;
//  screen1.Input = 0;
//
//  screen2.message = "Print Screen 2";
//  screen2.Val = 2;
//  screen2.Input = 0;
//  
//  screen3.message = "Print Screen 3";
//  screen3.Val = 3;
//  screen3.Input = 0;
//  
//  screen4.message = "Print Screen 4";
//  screen4.Val = 4;
//  screen4.Input = 0;

  lcd.clear();
  lcd.print("Balistics  V1.1");
  lcd.setCursor(0,1);
  lcd.print("Computer");
  delay(2000);
  lcd.clear();
  lcd.print(" A: Screen 1 ");
  lcd.setCursor(0,1);
  lcd.print(" B: Screen 2 ");
  delay(2000);
  lcd.clear();
  lcd.print(" C: Screen 3 ");
  lcd.setCursor(0,1);
  lcd.print(" D: Screen 4 ");
  delay(2000);
  lcd.clear();
  lcd.print("      B.C. V 1.1");
  lcd.setCursor(0,1);
  lcd.print("Awaiting input... ");
  screen currentScreen;
  char screenSelection = keypad.waitForKey();
  currentScreen = chooseScreen(screenSelection);
  }

void loop() {
  char commandKey;
  commandKey = keypad.waitForKey();
  processCommand(commandKey, currentScreen);

}
