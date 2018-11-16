#include "libIterativeRobot/commands/MiddleCollectorForward.h"
#include "libIterativeRobot/Robot.h"

MiddleCollectorForward::MiddleCollectorForward() {
  requires(Robot::middleCollector);
}

bool MiddleCollectorForward::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void MiddleCollectorForward::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void MiddleCollectorForward::execute() {
  // Code that runs when this command is scheduled to run

  Robot::middleCollector->runMiddleCollector(200);
}

bool MiddleCollectorForward::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void MiddleCollectorForward::end() {
  // Code that runs when isFinished() returns true.
}

void MiddleCollectorForward::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
