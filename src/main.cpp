/* Arduino based Shop Vacuum Controller
   ====================================
   
   Created by: Andy B
   Version:    1.3
   Date:       18/05/2022
   License:    GNU 3.0
   
   Detects a wired tool being used or a remote fob being pressed to control a shop vac with
   a 10A relay.
  */

// Include Libaries...
#include <Arduino.h>
#include <LibPrintf.h>

//Debug Control...
#define DEBUG 1

// Initialize delay times...
                    
#define onToolDelay 3                               // Delay between detecting the tool and
                                                    // nergising the vac relay
#define offDelayMin 3                               // Value sets the minimum off time delay
#define offDelayMax 30                              // Value sets the maximum off time delay
#define offDelayPin A7                              // pot connection to adjust the off time delay

int offDelay()                                      //  Calculate the off time delay based on the min
{                                                   //  and max delays and the pot setting
  int x=analogRead(offDelayPin);
  int offDelay=round((offDelayMax-offDelayMin)/1032.0*x+offDelayMin);         
  return(offDelay);
}

// Define Pins...
#define remoteInt 2                                 // ISR trigger for remote
#define remoteState 4                               // Current state of remote
#define toolInt 3                                   // ISR trigger for tool
#define toolState 5                                 // Current tool state

#define relay 7                                     // Relay
#define power 12                                    // Red "Power" LED
#define vac 11                                      // Yellow "Vacuum" LED
#define tool 10                                     // Green "Tool" LED
#define remote 9                                    // Blue "Remote" LED

// Prototype ISR Functions...
void remoteISR();                              
void toolISR();

// Flash the vacuum led...
void flash(int flashesPerSecond, int seconds)
{
  int rate=500/flashesPerSecond;
  for(int i=0; i<flashesPerSecond*seconds*2; i++)
  {
    digitalWrite(vac,not(digitalRead(vac)));
    delay(rate);
  }
}

// Setup...
void setup()
{
  #if DEBUG==1                                      // DEBUG: set up the serial port
    Serial.begin(9600);
  #endif
  
  // Initialise LED pins and blink LEDs...
  int led[4]={power, vac, tool, remote};
  for (int pin=0; pin<4; pin++)
  {
    pinMode(led[pin],OUTPUT);
    digitalWrite(led[pin],HIGH);
    delay(1000);
    digitalWrite(led[pin],LOW);
  }

  // Initialize relay pin...
  digitalWrite(relay,LOW);
  pinMode(relay,OUTPUT);

  #if DEBUG==1                                      // DEBUG: test the relay
    digitalWrite(relay,HIGH);
    delay(1000);
    digitalWrite(relay,LOW);
   #endif

   #if DEBUG==1                                     // DEBUG: Read the offDelay
    printf("offDelay = %d\n",offDelay());
    delay (2500);
  #endif

 // Turn on the power led...
  digitalWrite(power,HIGH);
}

// Loop...
void loop()
{
 
}