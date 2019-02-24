#include "libIterativeRobot/commands/MoveTuskFor.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

MoveTuskFor::MoveTuskFor(unsigned int duration, int speed) {
  this->duration = duration;
  this->speed = speed;

  requires(Robot::tusk);
  this->priority = 1;
}

bool MoveTuskFor::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void MoveTuskFor::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  printf("Initiating move tusk\n");
  startTime = pros::millis();
}

void MoveTuskFor::execute() {
  Robot::tusk->move(speed);
}

bool MoveTuskFor::isFinished() {
  return pros::millis() > (startTime + duration);
}

void MoveTuskFor::end() {
  // Code that runs when isFinished() returns true.
  Robot::tusk->move(0);
}

void MoveTuskFor::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  Robot::tusk->move(0);
}
