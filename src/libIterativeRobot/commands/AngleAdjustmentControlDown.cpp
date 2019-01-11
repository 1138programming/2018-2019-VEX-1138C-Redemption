#include "libIterativeRobot/commands/AngleAdjustmentControlDown.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

AngleAdjustmentControlDown::AngleAdjustmentControlDown() {
  requires(Robot::angleAdjustment);
  this->priority = 2;
}

bool AngleAdjustmentControlDown::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void AngleAdjustmentControlDown::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  // printf("AngleAdjustment control initialized\n");
}

void AngleAdjustmentControlDown::execute() {
  //printf("AngleAdjustment control running\n");
  Robot::angleAdjustment->move(-KMaxMotorSpeed);
}

bool AngleAdjustmentControlDown::isFinished() {
  return true;
}

void AngleAdjustmentControlDown::end() {
  // Code that runs when isFinished() returns true.
  //Robot::angleAdjustment->lock();
}

void AngleAdjustmentControlDown::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
