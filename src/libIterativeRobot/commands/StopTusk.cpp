#include "libIterativeRobot/commands/StopTusk.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

StopTusk::StopTusk() {
  requires(Robot::tusk);
  this->priority = DefaultCommandPriority; // Lowest priority
}

bool StopTusk::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void StopTusk::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  Robot::tusk->move(0);
}

void StopTusk::execute() {
  Robot::tusk->move(0);
  //printf("Stopping tusk\n");
}

bool StopTusk::isFinished() {
  return true;
}

void StopTusk::end() {
  // Code that runs when isFinished() returns true.
}

void StopTusk::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
