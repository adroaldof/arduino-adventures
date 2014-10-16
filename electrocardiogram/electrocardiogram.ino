/**
 * Electrocardiogram
 */

 #include <eHealth.h>

// The setup routine runs once when you press reset:
void setup() {
    Serial.begin(115200);
    Serial.println("Start Electrocardiogram measures");
    delay(2000);

    Serial.println("Begin reading");
    Serial.println("");
}

// The loop routine runs over and over again forever:
void loop() {

  float ECG = eHealth.getECG();

  Serial.print("ECG: ");
  Serial.print(ECG, 2);
  Serial.println(" V");

  delay(1000);
}
