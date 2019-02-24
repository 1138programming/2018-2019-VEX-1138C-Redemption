#include "libIterativeRobot/commands/TuskControlDown.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

TuskControlDown::TuskControlDown() {
  requires(Robot::tusk);
  this->priority = 2;
}

bool TuskControlDown::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void TuskControlDown::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  // printf("Tusk control initialized\n");
}

void TuskControlDown::execute() {
  //printf("Tusk control running\n");
  Robot::tusk->move(-KMaxMotorSpeed);
}

bool TuskControlDown::isFinished() {
  return true;
}

void TuskControlDown::end() {
  // Code that runs when isFinished() returns true.
  //Robot::tusk->lock();
}

void TuskControlDown::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
