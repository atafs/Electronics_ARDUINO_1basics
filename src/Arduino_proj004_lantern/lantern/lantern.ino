//GLOBAL VARIABLES

//LEDS PIN DIGITAL
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;

//SWITCH PIN DIGITAL
int switch0 = 6;
int switch1 = 7;
int switch2 = 8;
int switch3 = 9;
int switch4 = 10;

//TIME
int time = 1500;

//STATE
int state1 = LOW;

void setup() {
  //START PRINT
  Serial.begin(19200);
  
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
  //LANTERN ALGORITHM
  digitalWrite(led1, state1);
  if(digitalRead(switch0)) {
    Serial.println(digitalRead(led1));
    Serial.println(digitalRead(switch0));
    state1 = !state1;
    delay(time);  
  }
}
