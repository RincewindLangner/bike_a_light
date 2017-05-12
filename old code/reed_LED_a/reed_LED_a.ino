unsigned long startTime_BL = 0;
unsigned long startTime_IL = 0

const int LED_L = 2; // Left LED on digital 2 
const int REED_L = 4; // Left Reed switch on digital 3

const int LED_R = 3; // Left LED on digital 2 
const int REED_R = 5; // Left Reed switch on digital 3

const int INDI_L = 6; // Left indicator
const int INDI_R = 7; // Right indicator

int val_l = HIGH; // value to store the REED_L state
int val_r = HIGH; // value to store the REED_R state

int val_indi_l = LOW; // value to store the INDI_L state

const int state_breke = 0 // the state of the brake 0 is off
const int state_indi_l = 0 // left indicator state. 0 if off
const int state_indi_r = 0 // right indicator state. 0 is off

// temp code ideas 
//have it record the time and compare it for the indicator timing. Plus have a state for each stop light and indicator state.


void setup() {
  pinMode(LED_L, OUTPUT); // LED_L set to output
  digitalWrite(LED_L, HIGH); //start with LED_L as on
  pinMode(REED_L, INPUT); // REED_L set to input

  pinMode(LED_R, OUTPUT); // LED_R set to output
  digitalWrite(LED_R, HIGH); //start with LED_R as on
  pinMode(REED_R, INPUT); // REED_R set to input

  pinMode(INDI_L, INPUT); // INDI_L set as input for button
//  pinMode(INDI_R, INPUT); // INDI_R set as input for button

}

void loop() {
  // get the states
  
  
  // Left reed swich for sensing left brake leaver
  val_l = digitalRead(REED_L); // get and store state of reed switch - left
  if (val_l == LOW && INDI_L == LOW) {
    startTime_BL = millis();
    state_indi_l = 1
  }
  if (state_indi_l == 1 && (millis() - startTime) > 500);
    digitalWrite(LED_L, HIGH); // turn LED_L on 
  } 
  else {
    digitalWrite(LED_L, LOW); //turn LED_L off
  }

  // Right reed swich for sensing right brake leaver    
  val_r = digitalRead(REED_R); // get and store state of reed switch
  if (val_r == LOW) {
    digitalWrite(LED_R, HIGH); // turn LED_R on 
  } 
  else {
    digitalWrite(LED_R, LOW); //turn LED_R off
  }

  //Buttons for the indicators

  // left indicator
  val_indi_l = digitalRead(INDI_L); //Get value of INDI_L button
  startTime = millis();
  if (val_indi_l == HIGH) {
    digitalWrite(LED_L, HIGH);
  } 
  else {
    digitalWrite(LED_L, LOW);
  }
}
//  && (millis() - startTime) > 500
