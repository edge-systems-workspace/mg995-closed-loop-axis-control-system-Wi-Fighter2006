#include <Arduino.h>
#include <Servo.h>
/**
 * @file main.cpp
 * @brief MG995 Closed Loop Axis Control System
 * @author Piyush Choudhary
 * @date 2026-02-20
 *
 * @details
 * Implements a closed-loop position control system for the MG995 servo motor.
 * Analog feedback from a potentiometer is read via ADC and mapped to angular
 * position. A simple proportional control strategy adjusts the servo to
 * achieve the desired target angle set through Serial input.
 */

#define SERVO_PIN 9
#define FEEDBACK_PIN A0

Servo mg995;

int targetPosition = 90;
int feedbackValue = 0;
int currentAngle = 0;
int error = 0;

void setup() {

    Serial.begin(9600);
    mg995.attach(SERVO_PIN);

    Serial.println("=== MG995 Closed Loop Axis Control System Ready ===");
    Serial.println("Enter target angle (0–180): ");
}

void loop() {

    // Read target position from Serial
    if (Serial.available() > 0) {
        targetPosition = Serial.parseInt();
        targetPosition = constrain(targetPosition, 0, 180);
        Serial.print("New Target Set: ");
        Serial.println(targetPosition);
    }

    // Read feedback
    feedbackValue = analogRead(FEEDBACK_PIN);
    currentAngle = map(feedbackValue, 0, 1023, 0, 180);

    // Compute error
    error = targetPosition - currentAngle;

    // Closed-loop correction
    if (abs(error) > 2) {
        mg995.write(targetPosition);
    }

    Serial.print("Target: ");
    Serial.print(targetPosition);
    Serial.print(" | Current: ");
    Serial.println(currentAngle);

    delay(200);
}