#include "libIterativeRobot/commands/IntakeControl.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

IntakeControl::IntakeControl(bool In) {
  this->In = In;
  requires(Robot::intake);
  this->priority = 2;
}

bool IntakeControl::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void IntakeControl::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  // printf("Intake control initialized\n");
}

void IntakeControl::execute() {
  //printf("Intake control running\n");
  if (this->In)
    Robot::intake->move(KMaxMotorSpeed);
  else
    Robot::intake->move(-KMaxMotorSpeed);
}

bool IntakeControl::isFinished() {
  return true;
}

void IntakeControl::end() {
  // Code that runs when isFinished() returns true.
  //Robot::intake->lock();
}

void IntakeControl::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
