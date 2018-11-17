#include "libIterativeRobot/commands/PuncherControl.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

PuncherControl::PuncherControl() {
  requires(Robot::puncher);
  this->priority = 2;
}

bool PuncherControl::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void PuncherControl::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  // printf("Puncher control initialized\n");
}

void PuncherControl::execute() {
  //printf("Puncher control running\n");
  Robot::puncher->move(KMaxMotorSpeed);
}

bool PuncherControl::isFinished() {
  return true;
}

void PuncherControl::end() {
  // Code that runs when isFinished() returns true.
  //Robot::puncher->lock();
}

void PuncherControl::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
