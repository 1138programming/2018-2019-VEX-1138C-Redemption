#include "libIterativeRobot/commands/DriveWithJoy.h"

#include "libIterativeRobot/Robot.h"

DriveWithJoy::DriveWithJoy() {
  requires(Robot::base);
}

bool DriveWithJoy::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void DriveWithJoy::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void DriveWithJoy::execute() {
  // Code that runs when this command is scheduled to run
  Robot::base->moveBase(
    -( Robot::mainController->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) + Robot::mainController->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X) ),
    -( Robot::mainController->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) - Robot::mainController->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X) )
  );
}

bool DriveWithJoy::isFinished() {
  return true; // This is the default value anyways, so this method can be removed
}

void DriveWithJoy::end() {
  // Code that runs when isFinished() returns true.
}

void DriveWithJoy::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
