/**
 * Galvanic Skin Response (GSR)
 * Measure the electrical skin condutance based on it moisture level. Symphathetic
 * nervous system controls sweat glands and strong emotion moments can change the
 * electrical skin resistance
 */

#include <eHealth.h>

void setup () {
    Serial.begin(115200);
}


void loop () {
    float conductance = eHealth.getSkinConductance();
    float resistance = eHealth.getSkinResistance();
    float conductanceVoltage = eHealth.getSkinConductanceVoltage();

    Serial.print("C: ");
    Serial.print(conductance, 2);

    Serial.print("\t\tR: ");
    Serial.print(resistance, 2);

    Serial.print("\tCV: ");
    Serial.print(conductanceVoltage, 4);

    Serial.print("\n");

    delay(1000);
}
