#include "libIterativeRobot/commands/CollectorIdle.h"
#include "libIterativeRobot/Robot.h"

CollectorIdle::CollectorIdle() {
  requires(Robot::collector);
}

bool CollectorIdle::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void CollectorIdle::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void CollectorIdle::execute() {
  // Code that runs when this command is scheduled to run

  Robot::collector->runCollector(0);
}

bool CollectorIdle::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void CollectorIdle::end() {
  // Code that runs when isFinished() returns true.
}

void CollectorIdle::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
