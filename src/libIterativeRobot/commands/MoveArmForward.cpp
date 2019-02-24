#include "libIterativeRobot/commands/MoveArmForward.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"
#include "libIterativeRobot/subsystems/Arm.h"

MoveArmForward::MoveArmForward() {
  requires(Robot::arm);
}

bool MoveArmForward::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void MoveArmForward::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void MoveArmForward::execute() {
  Robot::arm->move(KMaxMotorSpeed);
  printf("Moving tusk\n");
}

bool MoveArmForward::isFinished() {
  return true;
}

void MoveArmForward::end() {
  // Code that runs when isFinished() returns true.
}

void MoveArmForward::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
