#include "libIterativeRobot/commands/TuskWithJoy.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

TuskWithJoy::TuskWithJoy() {
  requires(Robot::tusk);
  this->priority = 2;
}

bool TuskWithJoy::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void TuskWithJoy::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  speed = Robot::mainController->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
}

void TuskWithJoy::execute() {
  Robot::tusk->move(speed);
}

bool TuskWithJoy::isFinished() {
  return true;
}

void TuskWithJoy::end() {
  // Code that runs when isFinished() returns true.
}

void TuskWithJoy::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
