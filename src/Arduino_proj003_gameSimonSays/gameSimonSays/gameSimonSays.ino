#include <Mouse.h>

//GLOBAL VARIABLES

//LEDS PIN DIGITAL
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;

//SWITCH PIN DIGITAL
int switch1 = 7;
int switch2 = 8;
int switch3 = 9;
int switch4 = 10;

//TIME
int time = 250;

void setup() {
  //START PRINT
  Serial.begin(9600);
  
  //LED
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  //SWITCH
  pinMode(switch1, INPUT_PULLUP);
  pinMode(switch2, INPUT_PULLUP);
  pinMode(switch3, INPUT_PULLUP);
  pinMode(switch4, INPUT_PULLUP);

}

void loop() {
  //LED1
  digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.println(led1);
  delay(time);                // delay in between reads for stability
  
  digitalWrite(led1, LOW);   // turn the LED on (LOW is the voltage level)
  Serial.println(led1);
  delay(time);                // delay in between reads for stability

  //LED2
  digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.println(led2);
  delay(time);                // delay in between reads for stability
  
  digitalWrite(led2, LOW);   // turn the LED on (LOW is the voltage level)
  Serial.println(led2);
  delay(time);

    //LED3
  digitalWrite(led3, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.println(led3);
  delay(time);                // delay in between reads for stability
  
  digitalWrite(led3, LOW);   // turn the LED on (LOW is the voltage level)
  Serial.println(led3);
  delay(time);

    //LED4
  digitalWrite(led4, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.println(led4);
  delay(time);                // delay in between reads for stability
  
  digitalWrite(led4, LOW);   // turn the LED on (LOW is the voltage level)
  Serial.println(led4);
  delay(time);
  
}
