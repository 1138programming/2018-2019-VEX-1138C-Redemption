#include "libIterativeRobot/commands/CollectorForward.h"
#include "libIterativeRobot/Robot.h"

CollectorForward::CollectorForward() {
  requires(Robot::collector);
}

bool CollectorForward::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void CollectorForward::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void CollectorForward::execute() {
  // Code that runs when this command is scheduled to run

  Robot::collector->runCollector(200);
}

bool CollectorForward::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void CollectorForward::end() {
  // Code that runs when isFinished() returns true.
}

void CollectorForward::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
