#include "libIterativeRobot/commands/IntakeControlIn.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

IntakeControlIn::IntakeControlIn() {
  requires(Robot::intake);
  this->priority = 2;
}

bool IntakeControlIn::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void IntakeControlIn::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  // printf("Intake control initialized\n");
}

void IntakeControlIn::execute() {
  //printf("Intake control running\n");
  Robot::intake->move(KMaxMotorSpeed);
}

bool IntakeControlIn::isFinished() {
  return true;
}

void IntakeControlIn::end() {
  // Code that runs when isFinished() returns true.
  //Robot::intake->lock();
}

void IntakeControlIn::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
