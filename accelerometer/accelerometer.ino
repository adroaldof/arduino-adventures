/**
 * Detect five body position
 *
 * 1. Supine position
 * 2. Left lateral decubitus
 * 3. Rigth lateral decubitus
 * 4. Prone position
 * 5. Stand or sit position
 */

#include <eHealth.h>

void setup () {
    Serial.begin(115200);
    eHealth.initPositionSensor();
}

void loop () {
    Serial.print("Body Position: ");

    uint8_t pos = eHealth.getBodyPosition();
    eHealth.printPosition(pos);

    delay(1000);
}
