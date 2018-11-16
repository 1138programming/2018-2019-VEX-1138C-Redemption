#include "libIterativeRobot/commands/FlywheelBackwards.h"
#include "libIterativeRobot/Robot.h"

FlywheelBackwards::FlywheelBackwards() {
  requires(Robot::flywheel);
}

bool FlywheelBackwards::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void FlywheelBackwards::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void FlywheelBackwards::execute() {
  // Code that runs when this command is scheduled to run
  if (Robot::flywheel->getFlywheelVelocity() < 0) {
    Robot::flywheel->setFlywheel(0);
  } else {
    Robot::flywheel->setFlywheel(200);
  }
}

bool FlywheelBackwards::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void FlywheelBackwards::end() {
  // Code that runs when isFinished() returns true.
}

void FlywheelBackwards::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
