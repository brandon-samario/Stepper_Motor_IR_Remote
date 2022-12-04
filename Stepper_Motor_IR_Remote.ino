/*
  Purpose of this program is to know how to use and understand the funcion of stepper motors with the use of an IR remote.
  IR remote works with an IR reciever to receive a signal.
  IR reciever is connected to digital pin 6.
  Stepper motor connects ULN2003a driver module then connected to ardunio.
  Stepper motor connects to digital pins 8, 10, 9, 11 of the ardunio.
  The direction of the stepper motor is determined by the button pressed on the IR remote.
*/

#include "Stepper.h"
#include "IRremote.h"

#define STEPS  32 //Number of steps per revolution
int  Steps2Take; //2048 = 1 Revolution
int receiver = 6; //IR receiver will connect to Digital Pin 6 of ardunio

Stepper small_stepper(STEPS, 8, 10, 9, 11);

IRrecv irrecv(receiver); // create instance of 'irrecv'
decode_results results; // create instance of 'decode_results'

void setup() {
  // put your setup code here, to run once:

  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  // put your main code here, to run repeatedly:

  if (irrecv.decode(&results)) //check if IR signal was recieved

  {
    switch (results.value)

    {

      case 0xFD50AF: //UP button pressed
        small_stepper.setSpeed(500); //set speed of rotation
        Steps2Take  =  2048; //Rotate CW (clockwise)
        small_stepper.step(Steps2Take); //2048 = 1 revolution
        delay(2000);
        break;

      case 0xFD10EF: //DOWN button pressed
        small_stepper.setSpeed(500);
        Steps2Take  =  -2048;  // Rotate CCW (counter clock wise)
        small_stepper.step(Steps2Take); //2048 = 1 revolution
        delay(2000);
        break;

    }

    irrecv.resume(); //receive next value
  }


}
