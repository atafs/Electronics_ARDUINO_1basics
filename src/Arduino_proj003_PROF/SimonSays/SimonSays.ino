
int arrayBoard[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int arrayPlayer[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int counter = 0;
int playerCounter = 0;

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;

int switch1 = 12;
int switch2 = 8;
int switch3 = 9;
int switch4 = 11;

int idleValue = 0;

void clearArray(int* array) {
  for(int i=0; i<10; i++) {
    array[i] = 0;
  } 
}

boolean anyKeyPressed() {
 for(int i=1; i<5; ++i) {
   Serial.print("Switch");
   Serial.print(i);
   Serial.print(" = ");
   Serial.println(digitalRead(i+5));
 }
 return digitalRead(switch1) || digitalRead(switch2) || digitalRead(switch3) || digitalRead(switch4);
}

int keyPressed() {
  if(digitalRead(switch1)) {
   return led1;
  } else if(digitalRead(switch2)) {
   return led2;
  } else if(digitalRead(switch3)) {
   return led3;
  } else if(digitalRead(switch4)) {
   return led4;
  }
}

void pressPlay() {
  Serial.println("Not yet playing");
  if(!anyKeyPressed()) {
      int led = (idleValue++ % 4) + 2;
      digitalWrite(led, !digitalRead(led));
      delay(500);
      Serial.println("Still not playing");
    } else {
      clearLeds();
      delay(1000);
      generatePlay();
  }
}

void validPlay() {
  digitalWrite(arrayBoard[playerCounter], HIGH);
  delay(500);
  digitalWrite(arrayBoard[playerCounter++], LOW);
  delay(500);
}

void generatePlay() {
  arrayBoard[counter] = random(2, 6);
  digitalWrite(arrayBoard[counter], HIGH);
  delay(1000);
  digitalWrite(arrayBoard[counter++], LOW);
  Serial.println("Now playing");
  Serial.println(arrayBoard[counter-1]);
  playerCounter = 0;
}

void getNextPlay() {
  for(int i=0; i<counter; ++i) {
    Serial.println(arrayBoard[i]);
    digitalWrite(arrayBoard[i], HIGH);
    delay(1000);
    digitalWrite(arrayBoard[i], LOW);
    delay(100);
  }
  generatePlay();
}

void blinkWrong() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  delay(1000);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  delay(1000);
}

void blinkRight() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  delay(1000);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(1000);
}

void clearLeds () {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

void reset() {
  clearArray(arrayBoard);
  clearArray(arrayPlayer);
  counter = 0;
  playerCounter = 0;
  clearLeds();
}

void endGame(boolean victory) {
  if(victory) {
    blinkRight();
    blinkRight();
  } else {
    blinkWrong();
    blinkWrong();
  }
  reset();
  delay(1000);
}

void playOrGameWon() {
  if(playerCounter == counter) {
    blinkRight();
    if(counter == 10) {
      endGame(true);
    }
    getNextPlay();
  }
}

void setup() {
  Serial.begin(9600);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  
  pinMode(switch1, INPUT_PULLUP);
  pinMode(switch2, INPUT_PULLUP);
  pinMode(switch3, INPUT_PULLUP);
  pinMode(switch4, INPUT_PULLUP);
}

void loop() {
  Serial.println(digitalRead(switch1));

  if(arrayBoard[0] == 0) {
    pressPlay();
  } else {
    int key = keyPressed();
    if(key != 0) {
      Serial.print("Pressed switch");
      Serial.println(key - 1);
      arrayPlayer[playerCounter] = key;
      if(arrayPlayer[playerCounter] == arrayBoard[playerCounter]) {
        Serial.println("Coast clear");
        validPlay();
      } else {
        endGame(false);
        return;
      }
      playOrGameWon();
    }
  }
  delay(500);
}
