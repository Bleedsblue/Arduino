
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <String.h>
#include "LCDScreen.h"
LiquidCrystal lcd(5,4,3,2,1,0);

static const byte ROWS = 4; 
static const byte COLS = 4; 
static char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
static byte rowPins[ROWS] = {6,7,8,9}; 
static byte colPins[COLS] = {10,11,12,13}; 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

static const int NUM_SCREENS = 5;
LCDScreen screen[NUM_SCREENS]{{false},{true},{true},{true},{true}};
char key;
int screenNum = 0;


void initialDisplay(){
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Balistics  V1.1");
  lcd.setCursor(0,1);
  lcd.print("Computer");
  delay(2000);
}
//-------------------------------------------------------------------
//Function Name: Print Screen
//Purpose: Has the message, sensor value, and user input variables passed inside
//where they are set equal to the respective values of the corresponding screen object.
//-------------------------------------------------------------------
void printScreen(int screenNum, String message, float sensorVal, float userInput){
  screen[screenNum].printScreen(message, sensorVal, userInput);
  lcd.clear();
  lcd.print(message);
  lcd.setCursor(0,1);
  lcd.print("V: ");
  lcd.print(sensorVal);
//  if (screen[screenNum].takesInput == true){  //This will only print an input if 
    lcd.setCursor(8,1);               //the specific screen object was 
    lcd.print("I: ");               //initialized to have an input.
    lcd.print(userInput);
//  }
} // printScreen();

//-------------------------------------------------------------------
//Function Name: Input Screen
//Purpose: Takes an input from the keypad, stores it in a char array, 
//converts that array to a string, and then converts that string to 
//a float. this float is then passed to the member function of the chosen 
//screen and updates the value of the _userInput member. Interprits the
// '*' key as a decimal point.
//-------------------------------------------------------------------
void inputScreen(int screenNum){
 // if (screen[screenNum].takesInput != true)
 //   return;
  float userInput;
  char buf[screen[screenNum].MAX_LENGTH];
  int i;
  lcd.clear();
  lcd.print("Input: ");
  char key = keypad.waitForKey();
  for(i=0;i<screen[screenNum].MAX_LENGTH-1;i++){
    buf[i]= key;
    if(buf[i]=='*')
      buf[i] = '.';
    if(buf[i]=='#')
      break;
    lcd.print(buf[i]);
    key = keypad.waitForKey();
  }
  buf[i]=0;
  if(i == 0){
    userInput = 0;
    screen[screenNum].inputScreen(userInput);
    return;
  }
  userInput = atof (buf);
  screen[screenNum].inputScreen(userInput);
}

void setup() {
initialDisplay();
screen[0].updateMessage("I Am Screen 0");
screen[1].updateMessage("I Am Screen 1");
screen[2].updateMessage("I Am Screen 2");
screen[3].updateMessage("I Am Screen 3");
screen[4].updateMessage("I Am Screen 4");
for(int i = 0; i < NUM_SCREENS; i++){
  screen[i].updateVal(i * 3.14159);
}
}

void loop() {
  String message;
  float sensorVal;
  float userInput;
  key = keypad.waitForKey();

  switch(key){
    case 'A':             // Cursor up
      screenNum++;
      if(screenNum == NUM_SCREENS)
        screenNum = 0;
      printScreen(screenNum,message,sensorVal,userInput);
      break;
    case 'B':            // Cursor down
      screenNum--;
      if(screenNum == -1)
        screenNum = NUM_SCREENS - 1;
      printScreen(screenNum,message,sensorVal,userInput);
      break;      
    case 'D':            // Return to Home Screen
      screenNum = 0;
      printScreen(screenNum,message,sensorVal,userInput);
      break;
    case '*':            // Begin Input Process on Current Screen
      inputScreen(screenNum);
      printScreen(screenNum,message,sensorVal,userInput);
      break;         
  }



}






