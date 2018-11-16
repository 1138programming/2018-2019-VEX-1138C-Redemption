#include "libIterativeRobot/commands/StopBase.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

StopBase::StopBase() {
  requires(Robot::base);
  this->priority = DefaultCommandPriority; // Lowest priority
}

bool StopBase::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void StopBase::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void StopBase::execute() {
  //Robot::base->move(0, 0);
}

bool StopBase::isFinished() {
  return false;
}

void StopBase::end() {
  // Code that runs when isFinished() returns true.
}

void StopBase::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
