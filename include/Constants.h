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
const int frontLeftBasePort = 10;
const int frontRightBasePort = 16;
const int backLeftBasePort = 9;
const int backRightBasePort = 1;

const int leftCapFlipperPort = 4;
const int rightCapFlipperPort = 5;
const int puncherMotorPort = 6;
const int intakeMotorPort = 7;
//const int clawPort = 6;

//Motor and encoder constants
const int KMaxMotorSpeed = 127;
const int KMaxJoystickValue = 127;
const int encoderTicks = 360; // Encoder ticks in one revolution
const float rotationsPerInch = 31.400156410256; // TODO check if this is correct

// IME addresses
const unsigned char exampleIMEAddress = 0;

// Encoder ports
const int exampleEncoderTopPort = 0;
const int exampleEncoderBottomPort = 1;

// Global things that we need

#endif
