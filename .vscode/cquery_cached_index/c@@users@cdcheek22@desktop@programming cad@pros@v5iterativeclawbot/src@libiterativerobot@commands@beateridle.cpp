#include "libIterativeRobot/commands/BeaterIdle.h"
#include "libIterativeRobot/Robot.h"

BeaterIdle::BeaterIdle() {
  requires(Robot::beater);
}

bool BeaterIdle::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void BeaterIdle::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void BeaterIdle::execute() {
  // Code that runs when this command is scheduled to run

  Robot::beater->runBeater(0);
}

bool BeaterIdle::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void BeaterIdle::end() {
  // Code that runs when isFinished() returns true.
}

void BeaterIdle::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
