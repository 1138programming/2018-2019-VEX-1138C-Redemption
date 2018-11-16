#include "libIterativeRobot/commands/BeaterForward.h"
#include "libIterativeRobot/Robot.h"

BeaterForward::BeaterForward() {
  requires(Robot::beater);
}

bool BeaterForward::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void BeaterForward::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void BeaterForward::execute() {
  // Code that runs when this command is scheduled to run

  Robot::beater->runBeater(200);
}

bool BeaterForward::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void BeaterForward::end() {
  // Code that runs when isFinished() returns true.
}

void BeaterForward::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
