#include "main.h"
#include "libIterativeRobot/commands/StopBase.h"
#include "Constants.h"

Base::Base() {
  // Set up motors
  frontLeftMotor = Motor::getMotor(frontLeftBasePort);
  frontRightMotor = Motor::getMotor(frontRightBasePort);
  backLeftMotor = Motor::getMotor(backLeftBasePort);
  backRightMotor = Motor::getMotor(backRightBasePort);
}

void Base::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new StopBase());
}

/**
 * Move the base
 * @param left - speed of the left side
 * @param right - speed of the right side
 */

 bool Base::baseAtTarget() {
   return abs(frontLeftMotor->getMotorObject()->get_target_position() - frontLeftMotor->getMotorObject()->get_position()) <= 5; // Tune threshold and make a varaible
 }

void Base::move(int left, int right) {
  frontLeftMotor->setSpeed(left);
  frontRightMotor->setSpeed(-right);
  backLeftMotor->setSpeed(left);
  backRightMotor->setSpeed(-right);

}

void Base::moveBaseTo(int leftTarget, int rightTarget, int motorSpeed) {
  frontLeftMotor->getMotorObject()->move_relative(leftTarget, motorSpeed ? motorSpeed : 150); // TODO: Move last argument to a variable
  backLeftMotor->getMotorObject()->move_relative(leftTarget, motorSpeed ?  motorSpeed : 150);

  frontRightMotor->getMotorObject()->move_relative(rightTarget, motorSpeed ? motorSpeed : 150);
  backRightMotor->getMotorObject()->move_relative(rightTarget, motorSpeed ? motorSpeed : 150);
}
