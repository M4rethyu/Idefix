/*
Project: IDEFIX
Device under test: Red LED and Buttton
Tested with: Arduino Nano ATmega328P (Old Bootloader)
08.04.2022

LED - Arduino
Anode (long leg) - D7
Kathode (short leg) - 200Ohm Resistor - GND

Button
one side to 5V
other side via 1kOhm pull-down Resistor to GND and to D6
*/

#define LED 7
#define Button 6

int state = 0;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  //If button is pressed, wait 2s, turn on the LED, wait 1s, turn off the LED
  state = digitalRead(Button);
  if (state == HIGH)
  {
    delay (2000);
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
  }
}
