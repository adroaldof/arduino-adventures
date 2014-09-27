// Include library
#include <Servo.h>

// Declare a servo object
Servo servoMotor;
int angle = 0;
bool initialPosition = true;


void setup() {
    // Attach servo motor to pin 3
    servoMotor.attach(3);
    // Open serial port and set rate to 9600 bps
    Serial.begin(9600);
}

// Check servo arm angle and set to its 90 degree positon
void setInitialPosition () {
    servoMotor.write(180);
    initialPosition = false;
    delay(500);
    servoMotor.write(0);
    delay(500);
    servoMotor.write(90);
}

// Sort a angle between 0 and 179
int sortAngle () {
    return random(0, 179);
}

void loop () {
    // Check arm angle on start project
    if (initialPosition) {
        setInitialPosition();
    }

    // Sort angle and print it out
    int angleValue = sortAngle();
    Serial.print("Angle sorted: ");
    Serial.println(angleValue);

    // Make servo motor move its axis by a angle
    servoMotor.write(angleValue);
    delay(2000);
}
