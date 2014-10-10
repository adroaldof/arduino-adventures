// The connected digital pin board
int ledPin = 13;


// This run once when project starts
void setup () {
    // Initialize digital pin as output
    pinMode(ledPin, OUTPUT);
}

void loop () {
  digitalWrite(ledPin, HIGH);   // Turn led on
  delay(200);                   // Wait 200 milliseconds
  digitalWrite(ledPin, LOW);    // Turn led off
  delay(200);                   // Wait 200 milliseconds

  digitalWrite(ledPin, HIGH);
  delay(50);
  digitalWrite(ledPin, LOW);
  delay(50);

  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(3000);
}
