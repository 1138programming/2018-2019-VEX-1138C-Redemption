#include "libIterativeRobot/commands/MoveCapFlipper180Degrees.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

MoveCapFlipper180Degrees::MoveCapFlipper180Degrees() {

  requires(Robot::capFlipper);
  this->priority = 1;
}

bool MoveCapFlipper180Degrees::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void MoveCapFlipper180Degrees::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  printf("Initiating move capFlipper\n");
  startTime = pros::millis();

  Robot::capFlipper->move180(true);
}

void MoveCapFlipper180Degrees::execute() { // TODO Fix states
  if(abs(Motor::getMotor(leftCapFlipperPort)->getMotorObject()->get_target_position() - Motor::getMotor(leftCapFlipperPort)->getMotorObject()->get_position()) > 0){
    Robot::capFlipper->move180(true);
  }
  else
  {
    Robot::capFlipper->move180(false);
  }
}

bool MoveCapFlipper180Degrees::isFinished() {
  return Robot::capFlipper->capFlipperAtTarget();
}

void MoveCapFlipper180Degrees::end() {
  // Code that runs when isFinished() returns true.
  Robot::capFlipper->move(0);
}

void MoveCapFlipper180Degrees::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  Robot::capFlipper->move(0);
}
