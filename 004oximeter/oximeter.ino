/**
 * Measurement of amount of oxygen dissolved in blood based on detection of
 * Hemoglobin (HbO2) and Deoxyhemoglobin (Hb)
 * Hb absorbs 660 nm (red light spectra)
 * HbO2 absorbs 940 nm (infrared light spectra)
 *
 * 100%   - Carbon monoxide poisoning
 * 95-99% - Acceptable range
 * 88-94% - Acceptable to a hypoxic drive problem pacient
 */

#include <eHealth.h>
#include <PinChangeInt.h>

// Variables
int count = 0;
String output = "";

void setup() {
    Serial.begin(9600);
    eHealth.initPulsioximeter();
    // Atach the interruptions for using the polsioximeter
    PCintPort::attachInterrupt(6, readPulsioximeter, RISING);
}

void readPulsioximeter () {
    count ++;

    // Get only on 50 measures to reduce the latency
    if (count == 50) {
        eHealth.readPulsioximeter();
        count = 0;
    }
}

void loop () {
    int SPO2 = eHealth.getOxygenSaturation();
    int BPM = eHealth.getBPM();

    output = "BPM: " + String(BPM) + "  \%SpO2: " + String(SPO2);
    Serial.println(output);
    delay(1000);
}
