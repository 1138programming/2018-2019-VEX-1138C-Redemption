#include "libIterativeRobot/commands/MoveCapFlipperFor.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

MoveCapFlipperFor::MoveCapFlipperFor(unsigned int duration, int speed) {
  this->duration = duration;
  this->speed = speed;

  requires(Robot::capFlipper);
  this->priority = 1;
}

bool MoveCapFlipperFor::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void MoveCapFlipperFor::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  printf("Initiating move capFlipper\n");
  startTime = pros::millis();
}

void MoveCapFlipperFor::execute() {
    Robot::capFlipper->move(speed);
}

bool MoveCapFlipperFor::isFinished() {
  return pros::millis() > (startTime + duration);
}

void MoveCapFlipperFor::end() {
  // Code that runs when isFinished() returns true.
  Robot::capFlipper->move(0);
}

void MoveCapFlipperFor::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  Robot::capFlipper->move(0);
}
