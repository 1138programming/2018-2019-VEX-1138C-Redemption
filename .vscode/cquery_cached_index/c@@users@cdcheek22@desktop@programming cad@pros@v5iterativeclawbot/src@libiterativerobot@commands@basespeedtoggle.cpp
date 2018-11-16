#include "libIterativeRobot/commands/BaseSpeedToggle.h"
#include "libIterativeRobot/Robot.h"

BaseSpeedToggle::BaseSpeedToggle() {
  requires(Robot::robotBase);
}

bool BaseSpeedToggle::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void BaseSpeedToggle::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void BaseSpeedToggle::execute() {
  // Code that runs when this command is scheduled to run
  Robot::robotBase->toggleBaseSpeed();
}

bool BaseSpeedToggle::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void BaseSpeedToggle::end() {
  // Code that runs when isFinished() returns true.
}

void BaseSpeedToggle::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
