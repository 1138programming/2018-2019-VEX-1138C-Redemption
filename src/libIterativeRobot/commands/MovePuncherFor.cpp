#include "libIterativeRobot/commands/MovePuncherFor.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

MovePuncherFor::MovePuncherFor(unsigned int duration, int speed) {
  this->duration = duration;
  this->speed = speed;

  requires(Robot::puncher);
  this->priority = 1;
}

bool MovePuncherFor::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void MovePuncherFor::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  printf("Initiating move puncher\n");

  startTime = pros::millis();
}

void MovePuncherFor::execute() {
    Robot::puncher->move(speed);
}

bool MovePuncherFor::isFinished() {
  return pros::millis() > (startTime + duration);
}

void MovePuncherFor::end() {
  // Code that runs when isFinished() returns true.
  Robot::puncher->move(0);
}

void MovePuncherFor::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  Robot::puncher->move(0);
}
