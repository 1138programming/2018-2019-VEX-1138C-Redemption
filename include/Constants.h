/**
 * @file Constants.h
 * @brief Provides constants used throughout the entire code. Contains user-readable motor names
 */

 #include "abstractBaseClasses/Motor.h"

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define DEFAULT_TASK_TIME 10000
#define DELAY_TIME 10
#define MAX_MOTORS 20
#define MAX_FOLLOWERS 3

// Motor ports
const int leftFrontBaseMotorPort = 1;
const int rightFrontBaseMotorPort = 2;
const int leftBackBaseMotorPort = 3;
const int rightBackBaseMotorPort = 4;

//const int angleAdjustmentMotor1Port = 6;
//const int angleAdjustmentMotor2Port = 8;
const int puncherMotorPort = 7;
const int puncherMotor2Port = 9;
const int intakeMotorPort = 5;
const int armMotorPort = 6;
//const int clawPort = 6;

//Motor and encoder constants
const int KMaxMotorSpeed = 200;
const int KMaxJoystickValue = 200;
const int KMotorPosition = 200;
const int encoderTicks = 360; // Encoder ticks in one revolution
const float rotationsPerInch = 31.400156410256; // TODO check if this is correct

constexpr float slowSpeedMultiplier = 0.5;

// IME addresses
const unsigned char exampleIMEAddress = 0;

// Encoder ports
const int exampleEncoderTopPort = 0;
const int exampleEncoderBottomPort = 1;

// Global things that we need

#endif
