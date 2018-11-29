#include "main.h"
#include "libIterativeRobot/commands/StopPuncher.h"
#include "pros/motors.hpp"

Puncher::Puncher() {
  // Get arm motors
  puncherMotor = Motor::getMotor(puncherMotorPort);
  //armMotor->reverse();
  puncherMotor->getMotorObject()->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

void Puncher::initDefaultCommand() {
  setDefaultCommand(new StopPuncher());
}

/**
 * Move the arm
 * @param left - speed of the left side
 * @param right - speed of the right side
 */
void Puncher::move(int speed) {
  //printf("Puncher speed is %d\n", speed);
  puncherMotor->setSpeed(-speed);
}
void Puncher::brake(){
  //puncherMotor->getMotorObject()->set_brake_mode(E_MOTOR_BRAKE_HOLD);
}
