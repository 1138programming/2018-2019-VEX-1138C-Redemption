#include "libIterativeRobot/commands/CapFlipperControl.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

CapFlipperControl::CapFlipperControl(bool Forward) {
  this->Forward = Forward;
  requires(Robot::capFlipper);
  this->priority = 2;
}

bool CapFlipperControl::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void CapFlipperControl::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  // printf("CapFlipper control initialized\n");
}

void CapFlipperControl::execute() {
  //printf("CapFlipper control running\n");
  if (this->Forward)
    Robot::capFlipper->move(KMaxMotorSpeed);
  else
    Robot::capFlipper->move(-KMaxMotorSpeed);
}

bool CapFlipperControl::isFinished() {
  return true;
}

void CapFlipperControl::end() {
  // Code that runs when isFinished() returns true.
  //Robot::capFlipper->lock();
}

void CapFlipperControl::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
