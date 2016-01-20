//LIBRARIES
#include<LiquidCrystal.h>

//INITIALIZE LIBRARIES WITH NUMBERS WITH THE INTERFACE PINS
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  //START
  lcd.begin(16, 2);

  //CURSOR
  lcd.cursor();
}

void loop() {

  //CURSOR: to far right of the LCD
  lcd.setCursor(15, 0);
  lcd.autoscroll();

  //LOOP
  for(int i = 0; i < 10; i++) {
    lcd.print(i);
    delay(500);
  }

  //CLEAR
  lcd.clear();
 
}
