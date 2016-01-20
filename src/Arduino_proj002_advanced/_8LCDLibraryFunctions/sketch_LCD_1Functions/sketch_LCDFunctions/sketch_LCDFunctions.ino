//LIBRARIES
#include<LiquidCrystal.h>

//INITIALIZE LIBRARIES WITH NUMBERS WITH THE INTERFACE PINS
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  //START
  lcd.begin(16, 2);

  //WRITE: sends characters to LCD
  lcd.write(92);
  lcd.write("TEST");
  
  //SET
  lcd.setCursor(15, 1);

  //PRINT: sends characters to LCD
  lcd.print(97);
  lcd.print("97");
  lcd.print("EMBEBED SYSTEMS ARDUINO!!");

  //DELAY AND CLEAR LCD
  delay(3000);
  lcd.clear();
}

void loop() {
  //ALIGN RIGHT
  lcd.scrollDisplayRight();

  //DELAY (stability)
  delay(1000);

  //ALIGN LETF
  lcd.scrollDisplayLeft();
}
