#include "libIterativeRobot/commands/TuskControlUp.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

TuskControlUp::TuskControlUp() {
  requires(Robot::tusk);
  this->priority = 2;
}

bool TuskControlUp::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void TuskControlUp::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  // printf("Tusk control initialized\n");
}

void TuskControlUp::execute() {
  //printf("Tusk control running\n");
  Robot::tusk->move(KMaxMotorSpeed);
}

bool TuskControlUp::isFinished() {
  return true;
}

void TuskControlUp::end() {
  // Code that runs when isFinished() returns true.
  //Robot::tusk->lock();
}

void TuskControlUp::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
