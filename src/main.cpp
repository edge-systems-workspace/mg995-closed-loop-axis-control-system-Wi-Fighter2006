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

#define SERVO_PIN 9        // PWM control pin for MG995
#define FEEDBACK_PIN A0    // Analog feedback (potentiometer)

Servo mg995;               // Servo object

int targetPosition = 90;   // Desired angle
int feedbackValue = 0;     // Raw ADC feedback value

void setup() {

    Serial.begin(9600);          // Start Serial monitor
    mg995.attach(SERVO_PIN);     // Attach servo to pin

    Serial.println("=== MG995 Axis Control Initialized ===");
}

void loop() {
}