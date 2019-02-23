#include "libIterativeRobot/commands/DriveToPosition.h"
#include "libIterativeRobot/Robot.h"

DriveToPosition::DriveToPosition(int leftTarget, int rightTarget) {
  requires(Robot::base);
  this->leftTarget = leftTarget;
  this->rightTarget = rightTarget;
  this->motorSpeed = 0;
  this->priority = 51;
}

DriveToPosition::DriveToPosition(int leftTarget, int rightTarget, int motorSpeed) {
  requires(Robot::base);
  this->leftTarget = leftTarget;
  this->rightTarget = rightTarget;
  this->motorSpeed = motorSpeed;
  this->priority = 51;
}

bool DriveToPosition::canRun() {
  printf("DriveToPosition(%f, %f)\n", leftTarget, rightTarget);
  return true; // This is the default value anyways, so this method can be removed
}

void DriveToPosition::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  this->endTime = pros::millis() + ((((abs(leftTarget) + abs(rightTarget)) / 2) / motorSpeed) * 150); // Math to figure out when the motors will finish.
  Robot::base->moveBaseTo(leftTarget, rightTarget, motorSpeed);
}

void DriveToPosition::execute() {
  // Code that runs when this command is scheduled to run
}

bool DriveToPosition::isFinished() {
  return Robot::base->baseAtTarget(); //|| pros::millis() > endTime; // Makes sure that the base has finished before moving on.
}

void DriveToPosition::end() {
  // Code that runs when isFinished() returns true.
  Robot::base->moveBaseTo(0, 0);
}

void DriveToPosition::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
