#include "libIterativeRobot/commands/ArmWithJoy.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

ArmWithJoy::ArmWithJoy() {
  requires(Robot::arm);
  this->priority = 2;
  int armSpeed;
}

bool ArmWithJoy::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void ArmWithJoy::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  armSpeed = 2 * (Robot::mainController->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
}

void ArmWithJoy::execute() {
  Robot::arm->move(armSpeed);
}

bool ArmWithJoy::isFinished() {
  return true;
}

void ArmWithJoy::end() {
  // Code that runs when isFinished() returns true.
}

void ArmWithJoy::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
