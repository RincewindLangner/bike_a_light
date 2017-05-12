/* Brake lights and signals for bike backpak
 Two part code
 part 1 located on bike handle bars for brake sensing, indicator sensing and sending signal to the unit controlling the LED lights.
 */

// set up what variables you need here

const int RIGHT_BRAKE = 2; // Break lever - Right - INT0

const int BUTTON_RIGHT = 12; // Right brake button 

const int LED_RIGHT = 4; // Right LED light to indicate that it is on

int val_RIGHT = 0; //stores the value of right button

void setup() {

  // set up PIN modes here

  pinMode(RIGHT_BRAKE, INPUT);
  pinMode(LED_RIGHT, OUTPUT);
  pinMode(BUTTON_RIGHT, INPUT);
  

}

void loop() {
  val_RIGHT = digitalRead(BUTTON_RIGHT);
  if (val_RIGHT == HIGH) {
    digitalWrite(LED_RIGHT, HIGH);
  } else {
    digitalWrite(LED_RIGHT, LOW);
  }
  
}
