#include "libIterativeRobot/commands/BaseToggle.h"
#include "libIterativeRobot/Robot.h"

BaseToggle::BaseToggle() {
  requires(Robot::robotBase);
}

bool BaseToggle::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void BaseToggle::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void BaseToggle::execute() {
  // Code that runs when this command is scheduled to run
  Robot::robotBase->toggleBase();
}

bool BaseToggle::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void BaseToggle::end() {
  // Code that runs when isFinished() returns true.
}

void BaseToggle::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
