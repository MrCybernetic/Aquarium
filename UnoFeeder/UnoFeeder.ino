#include <AccelStepper.h>

/*
 * WIRING CONNECTIONS:
 *
 * ESP8266-01 <-> Arduino Uno:
 *   GPIO0    <-> Pin 3 (FEEDBACK_OUTPUT)
 *   GPIO2    <-> Pin 2 (TRIGGER_INPUT)
 *
 * DRV8825 <-> Arduino Uno:
 *   STEP     <-> Pin 4
 *   SLP      <-> Pin 5
 *   DIR      <-> Pin A5 (not used, but required for AccelStepper)
 */

// Pin connections to DRV8825
#define STEP_PIN 4
#define SLEEP_PIN 5
#define DIR_PIN A5 // Not used in this sketch, but required for AccelStepper

// Pins for ESP communication
#define TRIGGER_INPUT 2   // Input from ESP8266 GPIO2
#define FEEDBACK_OUTPUT 3 // Output to ESP8266 GPIO0

const int stepsPerRevolution = 200; // Adjust for your NEMA17 setup

AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

void setup()
{
  pinMode(SLEEP_PIN, OUTPUT);
  pinMode(FEEDBACK_OUTPUT, OUTPUT);
  pinMode(TRIGGER_INPUT, INPUT);
  digitalWrite(FEEDBACK_OUTPUT, LOW);
  digitalWrite(SLEEP_PIN, LOW);
  Serial.begin(9600);
  stepper.setMaxSpeed(4000);     // Max speed (steps/s)
  stepper.setAcceleration(3500); // Acceleration (steps/s²)
  stepper.setCurrentPosition(0);
}

void loop()
{
  if (digitalRead(TRIGGER_INPUT) == LOW)
  {
    Serial.println("Trigger LOW detected");
    unsigned long triggerStart = millis();
    // Wait and check if the signal stays LOW for 10 seconds
    while (digitalRead(TRIGGER_INPUT) == LOW && millis() - triggerStart < 10000)
    {
      delay(10);
    }
    // If still LOW after 10 seconds, execute feeding sequence
    if (digitalRead(TRIGGER_INPUT) == LOW && millis() - triggerStart >= 10000)
    {
      Serial.println("Feed command received");
      feed();
      sendFeedback();
      // Wait for trigger to go HIGH to avoid retriggering
      while (digitalRead(TRIGGER_INPUT) == LOW)
      {
        delay(10);
      }
    }
  }
  stepper.run(); // Required for AccelStepper
}

void feed()
{
  digitalWrite(SLEEP_PIN, HIGH);
  delay(10);
  // First half turn
  stepper.moveTo(stepper.currentPosition() + 3200); // 0.5 turn (200*32/2)
  while (stepper.distanceToGo() != 0)
  {
    stepper.run();
  }
  delay(500); // Pause between the two half turns
  // Second half turn (same direction)
  stepper.moveTo(stepper.currentPosition() + 3200); // 0.5 turn
  while (stepper.distanceToGo() != 0)
  {
    stepper.run();
  }
  digitalWrite(SLEEP_PIN, LOW);
}

void sendFeedback()
{
  digitalWrite(FEEDBACK_OUTPUT, HIGH);
  delay(1000); // Long enough for ESP to read
  digitalWrite(FEEDBACK_OUTPUT, LOW);
}
