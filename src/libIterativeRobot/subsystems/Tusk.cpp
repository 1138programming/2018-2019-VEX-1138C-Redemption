#include "main.h"
#include "libIterativeRobot/subsystems/Tusk.h"
#include "Constants.h"
#include "libIterativeRobot/commands/StopTusk.h"

Tusk::Tusk() {
  // Get arm motors
  tuskMotor1 = Motor::getMotor(tuskMotor1Port);
  //armMotor->reverse();
}

void Tusk::initDefaultCommand() {
  setDefaultCommand(new StopTusk());
}

/**
 * Move the arm
 * @param left - speed of the left side
 * @param right - speed of the right side
 */
void Tusk::move(int speed) {
  //printf("Tusk speed is %d\n", speed);
  tuskMotor1->getMotorObject()->move_velocity(speed);
}

bool Tusk::tuskAtTarget() {
  return abs(tuskMotor1->getMotorObject()->get_target_position() - tuskMotor1->getMotorObject()->get_position()) <= 5; // Tune threshold and make a varaible
}
