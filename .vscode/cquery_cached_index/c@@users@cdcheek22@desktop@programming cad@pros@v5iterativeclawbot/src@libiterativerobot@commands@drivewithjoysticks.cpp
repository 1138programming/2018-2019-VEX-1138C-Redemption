#include "libIterativeRobot/commands/DriveWithJoysticks.h"
#include "libIterativeRobot/Robot.h"

DriveWithJoysticks::DriveWithJoysticks() {
  requires(Robot::robotBase);
}

bool DriveWithJoysticks::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void DriveWithJoysticks::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void DriveWithJoysticks::execute() {
  // Code that runs when this command is scheduled to run
  Robot::robotBase->moveBase(
    -Robot::mainController->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y),
    -Robot::mainController->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y)
  );
}

bool DriveWithJoysticks::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void DriveWithJoysticks::end() {
  // Code that runs when isFinished() returns true.
}

void DriveWithJoysticks::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
