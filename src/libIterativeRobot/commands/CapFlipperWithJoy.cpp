#include "libIterativeRobot/commands/CapFlipperWithJoy.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

CapFlipperWithJoy::CapFlipperWithJoy() {
  requires(Robot::capFlipper);
  this->priority = 2;
}

bool CapFlipperWithJoy::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void CapFlipperWithJoy::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  speed = Robot::mainController->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
}

void CapFlipperWithJoy::execute() {
  Robot::capFlipper->move(speed);
}

bool CapFlipperWithJoy::isFinished() {
  return true;
}

void CapFlipperWithJoy::end() {
  // Code that runs when isFinished() returns true.
}

void CapFlipperWithJoy::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
