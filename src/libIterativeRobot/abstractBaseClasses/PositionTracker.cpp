#include "abstractBaseClasses/PositionTracker.h"

PositionTracker::PositionTracker(Motor* leftMotor, Motor* rightMotor, pros::ADIEncoder* backEncoder, float leftDist, float rightDist, float backDist, float wheelRadius, int ticksPerRev) {
  this->leftMotor = leftMotor;
  this->rightMotor = rightMotor;
  this->backEncoder = backEncoder;
  this->leftDist = leftDist;
  this->rightDist = rightDist;
  this->backDist = backDist;
  this->wheelRadius = wheelRadius;
  this->ticksPerRev = ticksPerRev;

  currentLeftEncoderValue = 0;
  currentRightEncoderValue = 0;
  currentBackEncoderValue = 0;
  previousLeftEncoderValue = 0;
  previousRightEncoderValue = 0;
  previousBackEncoderValue = 0;
  deltaLeftEncoderValue = 0;
  deltaRightEncoderValue = 0;
  deltaBackEncoderValue = 0;

  initialAngle = 0;
  absoluteAngle = 0;
  previousAngle = 0;
  deltaAngle = 0;
  averageAngle = 0;

  localXOffset = 0;
  localYOffset = 0;
  globalXOffset = 0;
  globalYOffset = 0;
  previousXOffset = 0;
  previousYOffset = 0;

  currentX = 0;
  currentY = 0;
}

float PositionTracker::ticksToInches(int ticks) {
  float c = M_PI * wheelRadius * wheelRadius;
  return c * (ticks / ticksPerRev);
}

void PositionTracker::update() {
  currentLeftEncoderValue = leftMotor->getEncoderValue();
  currentRightEncoderValue = rightMotor->getEncoderValue();
  currentBackEncoderValue = backEncoder->get_value();

  deltaLeftEncoderValue = currentLeftEncoderValue - previousLeftEncoderValue;
  deltaRightEncoderValue = currentLeftEncoderValue - previousRightEncoderValue;
  deltaBackEncoderValue = currentBackEncoderValue - previousBackEncoderValue;

  previousLeftEncoderValue = currentLeftEncoderValue;
  previousRightEncoderValue = currentRightEncoderValue;
  previousBackEncoderValue = currentBackEncoderValue;

  absoluteAngle = initialAngle + (ticksToInches(deltaLeftEncoderValue) - ticksToInches(deltaRightEncoderValue)) / (leftDist + rightDist);
  deltaAngle = absoluteAngle - previousAngle;
  previousAngle = absoluteAngle;

  if (deltaAngle == 0) {
    localXOffset = deltaBackEncoderValue;
    localYOffset = deltaRightEncoderValue;
  } else {
    localXOffset = 2 * sin(deltaAngle / 2) * ((deltaBackEncoderValue / deltaAngle) + backDist);
    localYOffset = 2 * sin(deltaAngle / 2) * ((deltaRightEncoderValue / deltaAngle) + rightDist);
  }

  averageAngle = absoluteAngle + deltaAngle / 2;

  float radius = sqrt((localXOffset * localXOffset) + (localYOffset * localYOffset));
  float angle = atan(localYOffset / localXOffset);
  float newAngle = angle - averageAngle;
  globalXOffset = radius * cos(newAngle);
  globalYOffset = radius * sin(newAngle);

  currentX = globalXOffset + previousXOffset;
  currentY = globalYOffset + previousYOffset;

  previousXOffset = globalXOffset;
  previousYOffset = globalYOffset;
}

float PositionTracker::getCurrentXPosition() {
  return currentX;
}

float PositionTracker::getCurrentYPosition() {
  return currentY;
}

float PositionTracker::getCurrentAngle() {
  return absoluteAngle;
}
