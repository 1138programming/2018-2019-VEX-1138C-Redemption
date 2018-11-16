#include "libIterativeRobot/commands/ArmControl.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

ArmControl::ArmControl(bool Up) {
  this->Up = Up;
  requires(Robot::arm);
  this->priority = 2;
}

bool ArmControl::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void ArmControl::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  // printf("Arm control initialized\n");
  Robot::arm->disablePID();
}

void ArmControl::execute() {
  //printf("Arm control running\n");
  if (this->Up)
    Robot::arm->move(KMaxMotorSpeed);
  else
    Robot::arm->move(-KMaxMotorSpeed);
}

bool ArmControl::isFinished() {
  return true;
}

void ArmControl::end() {
  // Code that runs when isFinished() returns true.
  //Robot::arm->lock();
}

void ArmControl::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
