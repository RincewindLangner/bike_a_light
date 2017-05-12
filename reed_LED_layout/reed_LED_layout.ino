#include <RHMesh.h>
#include <RH_RF24.h>
#include <RH_CC110.h>
#include <RH_RF69.h>
#include <RHGenericSPI.h>
#include <RHNRFSPIDriver.h>
#include <RH_MRF89.h>
#include <RHReliableDatagram.h>
#include <RH_Serial.h>
#include <RHSoftwareSPI.h>
#include <RH_NRF51.h>
#include <RHRouter.h>
#include <RH_NRF24.h>
#include <RH_NRF905.h>
#include <RHGenericDriver.h>
#include <RHTcpProtocol.h>
#include <RHCRC.h>
#include <RadioHead.h>
#include <RHHardwareSPI.h>
#include <RH_ASK.h>
#include <radio_config_Si4460.h>
#include <RH_TCP.h>
#include <RH_RF95.h>
#include <RHSPIDriver.h>
#include <RHDatagram.h>
#include <RH_RF22.h>

int ledState_L = LOW;             // ledState used to set the LED
unsigned long previousMillis_L = 0;        // will store last time LED was updated
long OnTime_L = 300;           // milliseconds of on-time
long OffTime_L = 500;          // milliseconds of off-time
const int LED_LI = 9;         // left indicator led

int ledState_R = LOW;             // ledState used to set the LED
unsigned long previousMillis_R = 0;        // will store last time LED was updated
long OnTime_R = 300;           // milliseconds of on-time
long OffTime_R = 500;          // milliseconds of off-time
const int LED_RI = A0;         // Right indicator led


const int LED_LB = 2; // Left LED on digital 2
const int BREAK_L = 4; // Left Reed switch on digital 3

const int LED_RB = 3; // Left LED on digital 2
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
  pinMode(LED_LB, OUTPUT); // LED_LB set to output
  digitalWrite(LED_LB, HIGH); //start with LED_LB as on
  pinMode(BREAK_L, INPUT); // BREAK_L set to input

  pinMode(LED_RB, OUTPUT); // LED_RB set to output
  digitalWrite(LED_RB, HIGH); //start with LED_RB as on
  pinMode(BREAK_R, INPUT); // BREAK_R set to input

  pinMode(INDI_L, INPUT); // INDI_L set as input for button
  pinMode(INDI_R, INPUT); // INDI_R set as input for button

  pinMode(LED_LI, OUTPUT); //LED_LI set as output to light LED
  pinMode(LED_RI, OUTPUT); //LED_RI set as output to light LED
  digitalWrite(LED_LI, LOW);
  digitalWrite(LED_RI, LOW);


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
    digitalWrite(LED_LB, HIGH); // turn LED_LB on 
  } 
  else {
    digitalWrite(LED_LB, LOW); //turn LED_LB off
  }
  // Break - right
  if (break_state_r == 1) {
    digitalWrite(LED_RB, HIGH); // turn LED_LB on 
  } 
  else {
    digitalWrite(LED_RB, LOW); //turn LED_LB off
  }

  //INDICATORS


  // Indicator - left
  // check to see if it's time to change the state of the LED
  if(indi_state_l == 1) {
    unsigned long currentMillis_L = millis();

    if((ledState_L == HIGH) && (currentMillis_L - previousMillis_L >= OnTime_L))
    {
      ledState_L = LOW;  // Turn it off
      previousMillis_L = currentMillis_L;  // Remember the time
      digitalWrite(LED_LI, ledState_L);  // Update the actual LED
    }
    else if ((ledState_L == LOW) && (currentMillis_L - previousMillis_L >= OffTime_L))
    {
      ledState_L = HIGH;  // turn it on
      previousMillis_L = currentMillis_L;   // Remember the time
      digitalWrite(LED_LI, ledState_L);	  // Update the actual LED
    }
  }


  if(indi_state_r == 1) {
    unsigned long currentMillis_R = millis();

    if((ledState_R == HIGH) && (currentMillis_R - previousMillis_R >= OnTime_R))
    {
      ledState_R = LOW;  // Turn it off
      previousMillis_R = currentMillis_R;  // Remember the time
      digitalWrite(LED_RI, ledState_R);  // Update the actual LED
    }
    else if ((ledState_R == LOW) && (currentMillis_R - previousMillis_R >= OffTime_R))
    {
      ledState_R = HIGH;  // turn it on
      previousMillis_R = currentMillis_R;   // Remember the time
      digitalWrite(LED_RI, ledState_R);	  // Update the actual LED
    }
  }


  /*
   //SENDING DATA
   
   
   */

}








