#include "libIterativeRobot/commands/CollectorForwardTimed.h"
#include "libIterativeRobot/Robot.h"

#include "api.h"

CollectorForwardTimed::CollectorForwardTimed(int mSecs) {
  requires(Robot::collector);
  runTime = mSecs;
}

bool CollectorForwardTimed::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void CollectorForwardTimed::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  startTime = pros::millis();
}

void CollectorForwardTimed::execute() {
  // Code that runs when this command is scheduled to run

  Robot::collector->runCollector(-200);
}

bool CollectorForwardTimed::isFinished() {
  return (pros::millis() - startTime) > runTime;
}

void CollectorForwardTimed::end() {
  // Code that runs when isFinished() returns true.
  Robot::collector->runCollector(0);
}

void CollectorForwardTimed::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
