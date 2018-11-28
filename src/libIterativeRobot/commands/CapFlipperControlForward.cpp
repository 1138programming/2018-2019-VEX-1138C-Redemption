#include "libIterativeRobot/commands/CapFlipperControlForward.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

CapFlipperControlForward::CapFlipperControlForward() {
  requires(Robot::capFlipper);
  this->priority = 2;
}

bool CapFlipperControlForward::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void CapFlipperControlForward::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  // printf("CapFlipper control initialized\n");
}

void CapFlipperControlForward::execute() {
  //printf("CapFlipper control running\n");
  Robot::capFlipper->move(KMaxMotorSpeed);
}

bool CapFlipperControlForward::isFinished() {
  return true;
}

void CapFlipperControlForward::end() {
  // Code that runs when isFinished() returns true.
  //Robot::capFlipper->lock();
}

void CapFlipperControlForward::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
