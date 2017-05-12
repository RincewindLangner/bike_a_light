/* Brake lights and signals for bike backpak
 Two part code
 part 1 located on bike handle bars for brake sensing, indicator sensing and sending signal to the unit controlling the LED lights.
 */

// set up what variables you need here

const int RB = 2; // Break lever - Right - INT0
const int LB = 3; // Break lever - Left - INT1
const int LEDL = 4; // LED left lights
const int LEDR = 5; // LED right lights
const int LEDB = 6; // LED break lights


int valLB = 0; // stores the state of the input pin
int valRB = 0; // stores the state of the input pin

int old_valLB = 0; //stores the previous value of "valLB"
int stateLB = 0;  // 0 = LB is closed while 1 = LB is open

int old_valRB = 0; //stores the previous value of "valRB"
int stateRB = 0;  // 0 = LR is closed while 1 = LR is open

unsigned long startTimeLB = 0;   // when did LB  begin pressing?
unsigned long startTimeLR = 0;   // when did LR  begin pressing?



void setup() {

  // set up PIN modes here

  pinMode(RB, INPUT_PULLUP);
  pinMode(LB, INPUT_PULLUP);
  pinMode(LEDL, OUTPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDB, OUTPUT);

}

void loop() {

  // have your loop code here

  // Do I have the interrupt code here or in the void setup area?

  valLB = digitalRead(LB);  // read input valure and store it

  // check if there was a trasition
  if ((valLB == HIGH) && (old_valLB == LOW)) {

    stateLB = 1 -stateLB;  // change the state from off to on or vice-versa

    startTimeLB = millis();  //millis() is the Arduino clock it returns how many milliseconds have passed since the board has been reset.

    // (this line remembers when the button was last pressed)
    delay(10);
  }
  {
    //check whether the buttom is being held down
    if ((valLB == HIGH) && (old_valLB == HIGH)) {
      // if the button is held for more thatn 500ms.
      if (stateLB == 1 && (millis() - startTimeLB) > 500) {

        digitalWrite(LEDL, HIGH); // Turns LED LB on
        delay(20); // delay of 20 milliseconds
        digitalWrite(LEDL, LOW); // Turns LED LB off

        digitalWrite(LEDL, HIGH); // Turns LED LB on
        delay(20); // delay of 20 milliseconds
        digitalWrite(LEDL, LOW); // Turns LED LB off
      }
    }
    old_valLB = valLB;   // val is now old, let's sotre it
  }
}


