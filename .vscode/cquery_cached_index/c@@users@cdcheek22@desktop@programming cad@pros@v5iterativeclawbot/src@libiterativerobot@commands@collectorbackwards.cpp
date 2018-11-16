#include "libIterativeRobot/commands/CollectorBackwards.h"
#include "libIterativeRobot/Robot.h"

CollectorBackwards::CollectorBackwards() {
  requires(Robot::collector);
}

bool CollectorBackwards::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void CollectorBackwards::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void CollectorBackwards::execute() {
  // Code that runs when this command is scheduled to run

  Robot::collector->runCollector(-200);
}

bool CollectorBackwards::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void CollectorBackwards::end() {
  // Code that runs when isFinished() returns true.
}

void CollectorBackwards::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
