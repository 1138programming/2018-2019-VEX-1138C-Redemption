#include "libIterativeRobot/commands/ClawControl.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

ClawControl::ClawControl(bool Open) {
  this->Open = Open;
  requires(Robot::claw);
  this->priority = 2;
}

bool ClawControl::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void ClawControl::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void ClawControl::execute() {
  //printf("Claw control running\n");
  if (this->Open)
    Robot::claw->move(KMaxMotorSpeed);
  else
    Robot::claw->move(-KMaxMotorSpeed);
}

bool ClawControl::isFinished() {
  return true;
}

void ClawControl::end() {
  // Code that runs when isFinished() returns true.
}

void ClawControl::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
