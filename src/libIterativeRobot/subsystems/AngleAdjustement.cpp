#include "main.h"
#include "libIterativeRobot/commands/StopAngleAdjustment.h"

AngleAdjustment::AngleAdjustment() {
  // Get arm motors
  angleAdjustmentMotor1 = Motor::getMotor(angleAdjustmentMotor1Port);
  angleAdjustmentMotor2 = Motor::getMotor(angleAdjustmentMotor2Port);
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
  angleAdjustmentMotor1->getMotorObject()->move_velocity(speed);
  angleAdjustmentMotor2->getMotorObject()->move_velocity(-speed);
}

bool AngleAdjustment::angleAdjustmentAtTarget() {
  return abs(angleAdjustmentMotor1->getMotorObject()->get_target_position() - angleAdjustmentMotor1->getMotorObject()->get_position()) <= 5; // Tune threshold and make a varaible
}
