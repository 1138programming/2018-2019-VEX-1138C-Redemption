#include "libIterativeRobot/commands/MiddleCollectorBackwards.h"
#include "libIterativeRobot/Robot.h"

MiddleCollectorBackwards::MiddleCollectorBackwards() {
  requires(Robot::middleCollector);
}

bool MiddleCollectorBackwards::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void MiddleCollectorBackwards::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void MiddleCollectorBackwards::execute() {
  // Code that runs when this command is scheduled to run

  Robot::middleCollector->runMiddleCollector(-200);
}

bool MiddleCollectorBackwards::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void MiddleCollectorBackwards::end() {
  // Code that runs when isFinished() returns true.
}

void MiddleCollectorBackwards::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
