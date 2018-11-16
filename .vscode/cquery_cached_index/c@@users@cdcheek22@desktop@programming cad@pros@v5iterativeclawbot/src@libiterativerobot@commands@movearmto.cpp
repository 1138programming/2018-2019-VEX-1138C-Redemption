#include "libIterativeRobot/commands/MoveArmTo.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

MoveArmTo::MoveArmTo(int target = 0) {
  requires(Robot::arm);
  this->priority = 1;
  this->target = target;
}

bool MoveArmTo::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void MoveArmTo::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  Robot::arm->enablePID();
  Robot::arm->setSetpoint(target);
}

void MoveArmTo::execute() {
  //printf("Moving arm to: %d\n", target);
}

bool MoveArmTo::isFinished() {
  return Robot::arm->atSetpoint();
}

void MoveArmTo::end() {
  // Code that runs when isFinished() returns true.
  //Robot::arm->lock();
}

void MoveArmTo::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
