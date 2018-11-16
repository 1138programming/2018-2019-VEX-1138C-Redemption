#include "libIterativeRobot/commands/MoveClawFor.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

MoveClawFor::MoveClawFor(unsigned int duration, int speed) {
  this->duration = duration;
  this->speed = speed;

  requires(Robot::claw);
  this->priority = 1;
}

bool MoveClawFor::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void MoveClawFor::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  //printf("Initializing claw\n");
  startTime = pros::millis();
}

void MoveClawFor::execute() {
    //printf("Moving claw\n");
    Robot::claw->move(speed);
}

bool MoveClawFor::isFinished() {
  return pros::millis() > (startTime + duration);
}

void MoveClawFor::end() {
  // Code that runs when isFinished() returns true.
  Robot::claw->move(0);
}

void MoveClawFor::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  Robot::claw->move(0);
}
