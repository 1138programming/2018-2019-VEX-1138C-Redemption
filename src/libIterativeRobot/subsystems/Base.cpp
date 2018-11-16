#include "main.h"

Base::Base() {
  // Set up motors
  frontLeftMotor = Motor::getMotor(frontLeftBasePort);
  frontRightMotor = Motor::getMotor(frontRightBasePort);
  backLeftMotor = Motor::getMotor(backLeftBasePort);
  backRightMotor = Motor::getMotor(backRightBasePort);
}

void Base::initDefaultCommand() {
  // Setup up a default command here
  //setDefaultCommand(new StopBase());
}

/**
 * Move the base
 * @param left - speed of the left side
 * @param right - speed of the right side
 */
void Base::move(int left, int right) {
  frontLeftMotor->setSpeed(left);
  frontRightMotor->setSpeed(right);
  backLeftMotor->setSpeed(left);
  backRightMotor->setSpeed(right);

}
