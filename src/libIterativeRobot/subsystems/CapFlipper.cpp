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
  leftCapFlipper->setSpeed(speed);
  rightCapFlipper->setSpeed(-speed);
}
