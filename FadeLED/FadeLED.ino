/**
  circuit: https://docs.arduino.cc/built-in-examples/basics/Fade/#circuit

  Connect the anode (the longer, positive leg) of your LED to digital output 
  pin 9 on your board through a 220 ohm resistor. Connect the cathode (the 
  shorter, negative leg) directly to ground. 

  Digital output pin 9 is a pulse-width modulation (PWM) pin, ensure you use a 
  PWM capable pin (indicated by a tilde (~)). 

  **Note on resistors**:
  The resistor is essential for safe operation as it limits the current flowing 
  through the LED, preventing damage to both the LED and the Arduino's output 
  pin. You can choose the resistor value based on the desired current using 
  Ohm's Law (V = IR) where V is the voltage of your board (5V or 3.3V) minus 
  the forward voltage for the LED you are using (typical for red would be 
  1.8 to 2.2 volts). In this case, using a 220-ohm resistor with an 
  Arduino UNO R3 (a 5V board) limits the current to a safe level for both the 
  LED and the Arduino pin. Adjusting the resistor value allows you to control 
  the LED's brightness while ensuring safe operation. For 5V boards you can 
  expect the LED to be visible to a resistor value of up to 1K Ohm.
  *********************

  The analogWrite() function used in the main loop requires two arguments: 
  The first passes the function the pin to write to, and the second 
  indicates what PWM value to write.

  In order to fade the LED off and on, gradually increase the PWM value from 
  0 (all the way off) to 255 (all the way on), and then back to 0 once again 
  to complete the cycle.

  The PWM value is set using the brightness variable. Each time through the 
  loop, it increases by the value of the variable fadeAmount. 

  If brightness is at either extreme of its value (either 0 or 255), then 
  fadeAmount is changed to its negative. The next time through the loop, 
  this change causes brightness to change direction as well.

  analogWrite() can change the PWM value very fast, so the delay at the end 
  of the sketch controls the speed of the fade. Try changing the value of the 
  delay and see how it changes the fading effect.

*/

int brightness = 0;
int fadeAmount = 5;  // how many points to fade the LED by

void setup() {
  // initialize pin 9 as an output: 
  pinMode(9, OUTPUT); 
}

void loop() {
  // set the brightness of pin 9:
  analogWrite(9, brightness);

  // update brightness for next iteration:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fade at the two extremes: 
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // delay in milliseconds to see the dimming effect:
  delay(30);
}
