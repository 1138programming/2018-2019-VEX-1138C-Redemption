#ifndef POSITIONTRACKER_H
#define POSITIONTRACKER_H

#include "Motor.h"
#include <math.h>

class PositionTracker {
  private:
    Motor* leftMotor;
    Motor* rightMotor;
    pros::ADIEncoder* backEncoder;

    float rightDist;
    float leftDist;
    float backDist;

    float wheelRadius;
    int ticksPerRev;

    int currentLeftEncoderValue;
    int currentRightEncoderValue;
    int currentBackEncoderValue;
    int previousLeftEncoderValue;
    int previousRightEncoderValue;
    int previousBackEncoderValue;
    int deltaLeftEncoderValue;
    int deltaRightEncoderValue;
    int deltaBackEncoderValue;

    float initialAngle;
    float absoluteAngle;
    float previousAngle;
    float deltaAngle;
    float averageAngle;

    float localXOffset;
    float localYOffset;
    float globalXOffset;
    float globalYOffset;
    float previousXOffset;
    float previousYOffset;

    float currentX;
    float currentY;

    float ticksToInches(int ticks);
  public:
    PositionTracker(Motor* leftMotor, Motor* rightMotor, pros::ADIEncoder* backEncoder, float leftDist, float rightDist, float backDist, float wheelRadius, int ticksPerRev);
    void update();
    float getCurrentXPosition();
    float getCurrentYPosition();
    float getCurrentAngle();
};

#endif
