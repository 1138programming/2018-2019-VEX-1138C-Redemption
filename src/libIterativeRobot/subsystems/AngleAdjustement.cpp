#include "main.h"
#include "libIterativeRobot/commands/StopAngleAdjustment.h"

AngleAdjustment::AngleAdjustment() {
  // Get arm motors
  angleAdjustmentMotor = Motor::getMotor(angleAdjustmentMotorPort);
  //armMotor->reverse();
}

void AngleAdjustment::initDefaultCommand() {
  setDefaultCommand(new StopAngleAdjustment());
}

/**
 * Move the arm
 * @param left - speed of the left side
 * @param right - speed of the right side
 */
void AngleAdjustment::move(int speed) {
  //printf("AngleAdjustment speed is %d\n", speed);
  angleAdjustmentMotor->getMotorObject()->move_velocity(speed);
}
void AngleAdjustment::move180(bool part, int speed1, int speed2) {
  if (part) {
    angleAdjustmentMotor->getMotorObject()->move_relative(450, speed1);
  }
  else {
    angleAdjustmentMotor->getMotorObject()->move_relative(450, speed2);
  }
}

bool AngleAdjustment::angleAdjustmentAtTarget() {
  return abs(angleAdjustmentMotor->getMotorObject()->get_target_position() - angleAdjustmentMotor->getMotorObject()->get_position()) <= 5; // Tune threshold and make a varaible
}
