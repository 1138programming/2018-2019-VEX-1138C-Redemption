#include "libIterativeRobot/commands/MoveArmBackward.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"
#include "libIterativeRobot/subsystems/Arm.h"

MoveArmBackward::MoveArmBackward() {
  requires(Robot::arm);
  this->priority = DefaultCommandPriority; // Lowest priority
}

bool MoveArmBackward::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void MoveArmBackward::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void MoveArmBackward::execute() {
  Robot::arm->move(-150);
  //printf("Stopping arm\n");
}

bool MoveArmBackward::isFinished() {
  return true;
}

void MoveArmBackward::end() {
  // Code that runs when isFinished() returns true.
}

void MoveArmBackward::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
