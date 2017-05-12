unsigned long startTime_l = 0;
unsigned long startTime_r = 0;
unsigned long startTime_l_old = 0;
unsigned long startTime_r_old = 0;


const int LED_L = 2; // Left LED on digital 2
const int BREAK_L = 4; // Left Reed switch on digital 3

const int LED_R = 3; // Left LED on digital 2
const int BREAK_R = 5; // Left Reed switch on digital 3

const int INDI_L = 6; // Left indicator
const int INDI_R = 7; // Right indicator

int val_break_l = HIGH; // value to store the BREAK_L state
int val_break_r = HIGH; // value to store the BREAK_R state

int val_indi_l = LOW; // value to store the INDI_L state
int val_indi_r = LOW; // value to store the INDI_R state

int break_state_l = 0; // states the left reed state - 0 = off(no break), 1 = on (break on)
int break_state_r = 0; // states the right reed state - 0 = off(no break), 1 = on (break on)

int indi_state_l = 0; // states the left monetray button indicator state - 0 not pressed, 1 is pressed
int indi_state_r = 0; // states the right monetray button indicator state - 0 not pressed, 1 is pressed

//send data state
int send_break_l = 0; // sets the state ready for sending
int send_break_r = 0; // sets the state ready for sending
int send_indi_l = 0; // sets the state ready for sending
int send_indi_r = 0; // sets the state ready for sending


void setup() {
  pinMode(LED_L, OUTPUT); // LED_L set to output
  digitalWrite(LED_L, HIGH); //start with LED_L as on
  pinMode(BREAK_L, INPUT); // BREAK_L set to input

  pinMode(LED_R, OUTPUT); // LED_R set to output
  digitalWrite(LED_R, HIGH); //start with LED_R as on
  pinMode(BREAK_R, INPUT); // BREAK_R set to input

  pinMode(INDI_L, INPUT); // INDI_L set as input for button
  pinMode(INDI_R, INPUT); // INDI_R set as input for button

  startTime_l = millis();
  startTime_r = millis();

}

void loop() {

  //Read the states of all switches
  val_break_l = digitalRead(BREAK_L); // get and store state of reed switch - left
  if (val_break_l == LOW) {
    break_state_l = 1;
  } 
  else {
    break_state_l = 0;
  }

  val_break_r = digitalRead(BREAK_R); // get and store state of reed switch
  if (val_break_r == LOW) {
    break_state_r = 1;
  } 
  else {
    break_state_r = 0;
  }

  val_indi_l = digitalRead(INDI_L);
  if (val_indi_l == HIGH) {
    indi_state_l = 1;
  } 
  else {
    indi_state_l = 0;
  }

  val_indi_r = digitalRead(INDI_R);
  if (val_indi_r == HIGH) {
    indi_state_r = 1;
  } 
  else {
    indi_state_r = 0;
  }

  //act on the states recorded
  //BREAKS
  //Break - left
  if (break_state_l == 1) {
    digitalWrite(LED_L, HIGH); // turn LED_L on 
  } 
  else {
    digitalWrite(LED_L, LOW); //turn LED_L off
  }
  // Break - right
  if (break_state_r == 1) {
    digitalWrite(LED_R, HIGH); // turn LED_L on 
  } 
  else {
    digitalWrite(LED_R, LOW); //turn LED_L off
  }

  //INDICATORS

  // Indicator - left
  if (indi_state_l == 1 && (millis() - startTime_l) < 5000) {
    send_indi_l = 1;
  } 
  
  if (indi_state_l == 0) {
    digitalWrite(LED_L, LOW);
  }

  // indicator - right
  if (indi_state_r == 1) {
    digitalWrite(LED_R, HIGH);
  } 
  else {
    digitalWrite(LED_R, LOW);
  }

  /*
   //SENDING DATA
   
   
   */

}


//   startTime = millis();
/*
&& indi_state_l == 1 && (millis() - startTime_l) > 5000
 
 
 need to set the time
 in the checking state section for the indicators, check to see if the time has moved past a set amount and if so send off signal
 */










