#include "libIterativeRobot/commands/CapFlipperControlBackward.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

CapFlipperControlBackward::CapFlipperControlBackward() {
  requires(Robot::capFlipper);
  this->priority = 2;
}

bool CapFlipperControlBackward::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void CapFlipperControlBackward::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  // printf("CapFlipper control initialized\n");
}

void CapFlipperControlBackward::execute() {
  //printf("CapFlipper control running\n");
  Robot::capFlipper->move(-KMaxMotorSpeed);
}

bool CapFlipperControlBackward::isFinished() {
  return true;
}

void CapFlipperControlBackward::end() {
  // Code that runs when isFinished() returns true.
  //Robot::capFlipper->lock();
}

void CapFlipperControlBackward::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
