/* Brake lights and signals for bike backpak
 Two part code
 part 1 located on bike handle bars for brake sensing, indicator sensing and sending signal to the unit controlling the LED lights.
 */

// set up what variables you need here

const int RB = 2; // Break lever - Right - INT0
//const int LB = 3; // Break lever - Left - INT1
//const int LEDL = 4; // LED left lights
//const int LEDR = 5; // LED right lights
//const int LEDB = 6; // LED break lights

//volatile int stateRB = LOW; //volatile is to hold the data in RAM and menory 

//int valLB = 0; // stores the state of the input pin
int valRB = LOW; // stores the state of the input pin

//int old_valLB = 0; //stores the previous value of "valLB"
//int stateLB = 0;  // 0 = LB is closed while 1 = LB is open

int old_valRB = 0; //stores the previous value of "valRB"
int stateRB = 0;  // 0 = LR is closed while 1 = LR is open

//unsigned long startTimeLB = 0;   // when did LB  begin pressing?
unsigned long startTimeRB = 0;   // when did RB  begin pressing?



void setup() {

  // set up PIN modes here

  pinMode(RB, INPUT_PULLUP);
//  pinMode(LB, INPUT_PULLUP);
//  pinMode(LEDL, OUTPUT);
  pinMode(LEDR, OUTPUT);
//  pinMode(LEDB, OUTPUT);

}

void loop() {
  if (valRB == HIGH) {
    delay(100);
    valRB = digitalRead(RB);
    if (valRB == HIGH) {
      delay(100);
      valRB = digitalRead(RB);
      if (valRB == LOW) {
        
      }
    }
    
    }
}

void Right_break() {
  
}
