#include "libIterativeRobot/commands/IntakeControlOut.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

IntakeControlOut::IntakeControlOut() {
  requires(Robot::intake);
  this->priority = 2;
}

bool IntakeControlOut::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void IntakeControlOut::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  // printf("Intake control initialized\n");
}

void IntakeControlOut::execute() {
  //printf("Intake control running\n");
  Robot::intake->move(-KMaxMotorSpeed);
}

bool IntakeControlOut::isFinished() {
  return true;
}

void IntakeControlOut::end() {
  // Code that runs when isFinished() returns true.
  //Robot::intake->lock();
}

void IntakeControlOut::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
