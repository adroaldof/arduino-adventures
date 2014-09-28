/**
 * Potentiometer Blink Led
 */

// Set constants and variables
const int POTENTIOMETER_PIN = 0;
const int LED = 13;
int potentiometerValue = 0;


void setup () {
    // Initialize digital pin as output
    pinMode(LED, OUTPUT);
}

void loop () {
    // Read potentiometer values from 0 up to 1023
    potentiometerValue = analogRead(POTENTIOMETER_PIN);

    // At potentiometers read set intevals between on and off
    digitalWrite(LED, HIGH);
    delay(potentiometerValue);
    digitalWrite(LED, LOW);
    delay(potentiometerValue);
}
