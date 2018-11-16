#include "libIterativeRobot/commands/StopArm.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

StopArm::StopArm() {
  requires(Robot::arm);
  this->priority = DefaultCommandPriority; // Lowest priority
}

bool StopArm::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void StopArm::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  Robot::arm->move(0);
  //Robot::arm->lock();
  //Robot::arm->enablePID();
}

void StopArm::execute() {
  Robot::arm->move(0);
  //printf("Stopping arm\n");
}

bool StopArm::isFinished() {
  return false;
}

void StopArm::end() {
  // Code that runs when isFinished() returns true.
}

void StopArm::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
