/*
 *  Stargate
 * 
 */

#include <TimerOne.h>

#define EN 8/* Enable pin for all stepper outputs */
#define X_DIR 5/* Direction-Pin for X-axis */
#define X_STEP 2/* Step-Pin for X-axis */

int Count = 0; /* Counter to count number of steps made */
boolean Direction = LOW; /* Rotational direction of stepper motors*/

int incomingByte = 0;

boolean stop = false;

const int stepsPerRev=200; // 1 Seul tour
int pulseWidthMicros = 100;  // microseconds
int millisBtwnSteps = 10000;

void setup(){
  Serial.begin(9600);


pinMode(EN, OUTPUT);
pinMode(X_DIR, OUTPUT);
pinMode(X_STEP, OUTPUT);

digitalWrite(EN, LOW); //Low to enable

 
}

void loop(){


  if (Serial.available() > 0) {

    incomingByte = Serial.read();

    Serial.print("I received: ");
    Serial.println(incomingByte);
    Serial.println(incomingByte, DEC);
    
   

    // Counter Clockwise
    if ( incomingByte == 101) {
     digitalWrite(X_DIR, HIGH);
      for (int i = 0; i < stepsPerRev; i++) {
        digitalWrite(X_STEP, HIGH);
        delayMicroseconds(pulseWidthMicros);
        digitalWrite(X_STEP, LOW);
        delayMicroseconds(millisBtwnSteps);
      }
      delay(1000); // One second delay
    }

    // Clockwise
    if ( incomingByte == 114) {
          digitalWrite(X_DIR, LOW);
      for (int i = 0; i < stepsPerRev; i++) {
        digitalWrite(X_STEP, HIGH);
        delayMicroseconds(pulseWidthMicros);
        digitalWrite(X_STEP, LOW);
        delayMicroseconds(millisBtwnSteps);
      }
      delay(1000); // One second delay
    }
      
  }
  

} 
