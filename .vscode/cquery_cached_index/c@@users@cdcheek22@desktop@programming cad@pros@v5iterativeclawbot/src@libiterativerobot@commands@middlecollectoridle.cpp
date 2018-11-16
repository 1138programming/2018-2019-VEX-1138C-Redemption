#include "libIterativeRobot/commands/MiddleCollectorIdle.h"
#include "libIterativeRobot/Robot.h"

MiddleCollectorIdle::MiddleCollectorIdle() {
  requires(Robot::middleCollector);
}

bool MiddleCollectorIdle::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void MiddleCollectorIdle::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void MiddleCollectorIdle::execute() {
  // Code that runs when this command is scheduled to run

  Robot::middleCollector->runMiddleCollector(0);
}

bool MiddleCollectorIdle::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void MiddleCollectorIdle::end() {
  // Code that runs when isFinished() returns true.
}

void MiddleCollectorIdle::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
