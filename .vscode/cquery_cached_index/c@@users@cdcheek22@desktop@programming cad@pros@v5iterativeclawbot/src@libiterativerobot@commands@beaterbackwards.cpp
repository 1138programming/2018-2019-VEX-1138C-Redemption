#include "libIterativeRobot/commands/BeaterBackwards.h"
#include "libIterativeRobot/Robot.h"

BeaterBackwards::BeaterBackwards() {
  requires(Robot::beater);
}

bool BeaterBackwards::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void BeaterBackwards::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void BeaterBackwards::execute() {
  // Code that runs when this command is scheduled to run

  Robot::beater->runBeater(-200);
}

bool BeaterBackwards::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void BeaterBackwards::end() {
  // Code that runs when isFinished() returns true.
}

void BeaterBackwards::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
