#include "libIterativeRobot/commands/FlywheelRevUp.h"
#include "libIterativeRobot/Robot.h"

FlywheelRevUp::FlywheelRevUp() {
  priority = 45; // Less priority, so that we can be interrupted when we actually want to shoot
  requires(Robot::flywheel);
}

bool FlywheelRevUp::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void FlywheelRevUp::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  Robot::flywheel->setFlywheel(-200);
}

void FlywheelRevUp::execute() {
  // Code that runs when this command is scheduled to run
}

bool FlywheelRevUp::isFinished() {
  return abs(Robot::flywheel->getFlywheelVelocity()) > 180; // This is the default va  lue anyways, so this method can be removed
}

void FlywheelRevUp::end() {
  // Code that runs when isFinished() returns true.
}

void FlywheelRevUp::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
