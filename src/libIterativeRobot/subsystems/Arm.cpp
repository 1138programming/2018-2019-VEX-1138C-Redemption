#include "main.h"
#include "libIterativeRobot/subsystems/Arm.h"
#include "libIterativeRobot/commands/ArmWithJoy.h"
#include "libIterativeRobot/commands/StopArm.h"

Arm::Arm() {
  // Get arm motors
  armMotor = Motor::getMotor(armMotorPort);
  //armMotor->reverse();
}

void Arm::initDefaultCommand() {
  setDefaultCommand(new StopArm());
}

/**
 * Move the arm
 * @param left - speed of the left side
 * @param right - speed of the right side
 */
void Arm::move(int speed) {
  //printf("Intake speed is %d\n", speed);
  armMotor->getMotorObject()->move_velocity(speed);
}

bool Arm::armAtTarget() {
 return abs(armMotor->getMotorObject()->get_target_position() - armMotor->getMotorObject()->get_position()) <= 5; // Tune threshold and make a varaible
}
