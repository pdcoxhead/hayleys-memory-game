/***************************
* Hayley's Electronic Dice *
****************************
  ---------
 | O       |
 |    O    |
 |       O |
  ---------

***************************/
//              1  2  3   4   5   6
int dice[6] = { 8, 9, 10, 11, 12, 13 };
int button = 2;
int buttonPressed = false;

/*
 * Connect the LEDs to the pins in dice
 * Connect the button to pin 2
 * To roll the dice press the button!
 */

void setup() {
//  Serial.begin(9600);
//  Serial.println("Hayley's Dice");
  pinMode(button, INPUT);
  for (int i = 0; i < sizeof(dice); i++) {
    pinMode(dice[i], OUTPUT);
  }
}

void loop() {
  while (digitalRead(button) == 0) {
    random(1, 7);
    //Serial.println("offPress");
    //Make a noise ???
    //Cycle the light???
  }
  while (digitalRead(button) != 0) {
    random(1, 7);
  }
  setLights(random(1, 7));

}

void setLights(int value) {
  clearLights();
  
  for (int i = 0; i < min(value, sizeof(dice)); i++) {
    digitalWrite(dice[i], HIGH);
  }
}

void clearLights() {
  for (int i = 0; i < sizeof(dice); i++) {
    digitalWrite(dice[i], LOW);
  } 
}

