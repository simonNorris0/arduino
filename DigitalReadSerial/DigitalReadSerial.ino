/**
  Circuit: https://docs.arduino.cc/built-in-examples/basics/DigitalReadSerial/#circuit

  Connect three wires to the board. The first two, red and black, connect to 
  the two long vertical rows on the side of the breadboard to provide access 
  to the 5 volt supply and ground. The third wire goes from digital pin 2 to 
  one leg of the pushbutton. That same leg of the button connects through a 
  pull-down resistor (here 10k ohm) to ground. The other leg of the button 
  connects to the 5 volt supply.

  Pushbuttons or switches connect two points in a circuit when you press them. 
  When the pushbutton is open (unpressed) there is no connection between the 
  two legs of the pushbutton, so the pin is connected to ground (through the 
  pull-down resistor) and reads as LOW, or 0. When the button is closed 
  (pressed), it makes a connection between its two legs, connecting the pin 
  to 5 volts, so that the pin reads as HIGH, or 1.

  If you disconnect the digital i/o pin from everything, its reading may 
  change erratically. This is because the input is "floating" - that is, it 
  doesn't have a solid connection to voltage or ground, and it will randomly 
  return either HIGH or LOW. That's why you need a pull-down resistor in the 
  circuit.
  
  When your button is pressed, 5 volts will freely flow through your circuit, 
  and when it is not pressed, the input pin will be connected to ground through 
  the 10k ohm resistor. This is a digital input, meaning that the switch can 
  only be in either an on state (seen by your Arduino as a "1", or HIGH) or an 
  off state (seen by your Arduino as a "0", or LOW), with nothing in between.

  when you open your Serial Monitor in the Arduino Software (IDE), you will 
  see a stream of "0"s if your switch is open, or "1"s if your switch is closed.

*/

void setup() {
  // Initiate serial communications at 9600 bits of data per second:
  Serial.begin(9600); 
  // Initialize digital pin 2 as input, the pin that will read output 
  // from the button:
  pinMode(2, INPUT);  
}

void loop() {
  // use an integer to store the binary read (0 or 1) from digital pin 2:
  int sensorVal = digitalRead(2);
  // print the sensor value on the serial monitor (on the computer):
  Serial.println(sensorVal);
  // delay in microseconds inbetween reads for stability:
  delay(500); 
}
