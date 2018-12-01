#include "libIterativeRobot/commands/StopCapFlipper.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

StopCapFlipper::StopCapFlipper() {
  requires(Robot::capFlipper);
  this->priority = DefaultCommandPriority; // Lowest priority
}

bool StopCapFlipper::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void StopCapFlipper::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  Robot::capFlipper->move(0);
}

void StopCapFlipper::execute() {
  Robot::capFlipper->move(0);
  //printf("Stopping capFlipper\n");
}

bool StopCapFlipper::isFinished() {
  return true;
}

void StopCapFlipper::end() {
  // Code that runs when isFinished() returns true.
}

void StopCapFlipper::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
