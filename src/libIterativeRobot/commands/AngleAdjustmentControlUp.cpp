#include "libIterativeRobot/commands/AngleAdjustmentControlUp.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

AngleAdjustmentControlUp::AngleAdjustmentControlUp() {
  requires(Robot::angleAdjustment);
  this->priority = 2;
}

bool AngleAdjustmentControlUp::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void AngleAdjustmentControlUp::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  // printf("AngleAdjustment control initialized\n");
}

void AngleAdjustmentControlUp::execute() {
  //printf("AngleAdjustment control running\n");
  Robot::angleAdjustment->move(KMaxMotorSpeed);
}

bool AngleAdjustmentControlUp::isFinished() {
  return true;
}

void AngleAdjustmentControlUp::end() {
  // Code that runs when isFinished() returns true.
  //Robot::angleAdjustment->lock();
}

void AngleAdjustmentControlUp::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
