#include "main.h"
#include "libIterativeRobot/commands/StopCapFlipper.h"

CapFlipper::CapFlipper() {
  // Get arm motors
  leftCapFlipper = Motor::getMotor(leftCapFlipperPort);
  rightCapFlipper = Motor::getMotor(rightCapFlipperPort);
  //armMotor->reverse();
}

void CapFlipper::initDefaultCommand() {
  setDefaultCommand(new StopCapFlipper());
}

/**
 * Move the arm
 * @param left - speed of the left side
 * @param right - speed of the right side
 */
void CapFlipper::move(int speed) {
  //printf("CapFlipper speed is %d\n", speed);
  leftCapFlipper->getMotorObject()->move_velocity(speed);
  rightCapFlipper->getMotorObject()->move_velocity(-speed);
}
void CapFlipper::move180(bool part, int speed1, int speed2) {
  if (part) {
    leftCapFlipper->getMotorObject()->move_relative(450, speed1);
    rightCapFlipper->getMotorObject()->move_relative(450, speed1);
  }
  else {
    leftCapFlipper->getMotorObject()->move_relative(450, speed2);
    rightCapFlipper->getMotorObject()->move_relative(450, speed2);
  }
}

bool CapFlipper::capFlipperAtTarget() {
  return abs(leftCapFlipper->getMotorObject()->get_target_position() - leftCapFlipper->getMotorObject()->get_position()) <= 5; // Tune threshold and make a varaible
}
