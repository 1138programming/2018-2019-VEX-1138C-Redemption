#include "libIterativeRobot/commands/MoveArmFor.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

MoveArmFor::MoveArmFor(unsigned int duration, int speed) {
  this->duration = duration;
  this->speed = speed;

  requires(Robot::arm);
  this->priority = 1;
}

bool MoveArmFor::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void MoveArmFor::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  printf("Initiating move arm\n");
  pros::delay(1000);
  startTime = pros::millis();
}

void MoveArmFor::execute() {
    Robot::arm->move(speed);
}

bool MoveArmFor::isFinished() {
  return pros::millis() > (startTime + duration);
}

void MoveArmFor::end() {
  // Code that runs when isFinished() returns true.
  Robot::arm->move(0);
}

void MoveArmFor::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  Robot::arm->move(0);
}
