/**
 * Simple project to show how to use a Real Time Operation System working
 * it will blink a led and print some task on monitor
 */

#include <FreeRTOS_AVR.h>

static void blinkTask(void *params);
static void printTask(void *params);

#ifndef PINS_DEFINED
const uint8_t LED_PIN = 13;
volatile uint32_t count = 0;
#endif

TaskHandle_t blink;

void setup (void) {
    Serial.begin(9600);

    while (!Serial) {}

    // Blink task
    xTaskCreate(
        blinkTask,
        "Blink Task",
        configMINIMAL_STACK_SIZE + 50,
        NULL,
        tskIDLE_PRIORITY + 1,
        &blink
    );

    // Print task
    xTaskCreate(
        printTask,
        "Print Task",
        configMINIMAL_STACK_SIZE + 100,
        NULL,
        tskIDLE_PRIORITY + 2,
        NULL
    );

    vTaskStartScheduler();

    Serial.print(F("Die"));

    while (1) {;}
}

void loop (void) {
    while (1) {
        noInterrupts();
        count++;
        interrupts();
    }
}

static void blinkTask (void *) {
    pinMode(LED_PIN, OUTPUT);

    for (;;) {
        digitalWrite(LED_PIN, HIGH);
        vTaskDelay((50L * configTICK_RATE_HZ) / 1000L);
        digitalWrite(LED_PIN, LOW);
        vTaskDelay((100L * configTICK_RATE_HZ) / 1000L);
        digitalWrite(LED_PIN, HIGH);
        vTaskDelay((50L * configTICK_RATE_HZ) / 1000L);
        digitalWrite(LED_PIN, LOW);
        vTaskDelay((100L * configTICK_RATE_HZ) / 1000L);
        digitalWrite(LED_PIN, HIGH);
        vTaskDelay((1000L * configTICK_RATE_HZ) / 1000L);
        digitalWrite(LED_PIN, LOW);
        vTaskDelay((1500L * configTICK_RATE_HZ) / 1000L);
    }
}

static void printTask (void *) {
    while (1) {
        vTaskDelay(configTICK_RATE_HZ);

        Serial.print("Count: ");
        Serial.print(count);

        Serial.print(F(" - Unused Stack: "));
        Serial.print(uxTaskGetStackHighWaterMark(blink));
        Serial.print(" ");
        Serial.print(uxTaskGetStackHighWaterMark(0));
        Serial.print(" ");
        Serial.println(freeHeap());

        count = 0;
    }
}
