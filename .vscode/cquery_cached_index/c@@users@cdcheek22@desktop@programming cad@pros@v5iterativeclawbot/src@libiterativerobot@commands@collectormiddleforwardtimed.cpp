#include "libIterativeRobot/commands/CollectorMiddleForwardTimed.h"
#include "libIterativeRobot/Robot.h"

#include "api.h"

CollectorMiddleForwardTimed::CollectorMiddleForwardTimed(int mSecs) {
  requires(Robot::middleCollector);
  runTime = mSecs;
  startTime = pros::millis();
}

bool CollectorMiddleForwardTimed::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void CollectorMiddleForwardTimed::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  startTime = pros::millis();
}

void CollectorMiddleForwardTimed::execute() {
  // Code that runs when this command is scheduled to run

  Robot::middleCollector->runMiddleCollector(-200);
}

bool CollectorMiddleForwardTimed::isFinished() {
  return (pros::millis() - startTime) > runTime;
}

void CollectorMiddleForwardTimed::end() {
  // Code that runs when isFinished() returns true.
  Robot::middleCollector->runMiddleCollector(0);
}

void CollectorMiddleForwardTimed::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
