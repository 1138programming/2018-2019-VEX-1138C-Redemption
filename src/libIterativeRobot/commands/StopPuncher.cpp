#include "libIterativeRobot/commands/StopPuncher.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

StopPuncher::StopPuncher() {
  requires(Robot::puncher);
  this->priority = DefaultCommandPriority; // Lowest priority
}

bool StopPuncher::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void StopPuncher::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  Robot::puncher->move(0);
}

void StopPuncher::execute() {
  Robot::puncher->move(0);
  //printf("Stopping puncher\n");
}

bool StopPuncher::isFinished() {
  return true;
}

void StopPuncher::end() {
  // Code that runs when isFinished() returns true.
}

void StopPuncher::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
