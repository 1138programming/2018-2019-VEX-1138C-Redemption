#include "main.h"
#include "libIterativeRobot/subsystems/Intake.h"
#include "libIterativeRobot/commands/StopIntake.h"

Intake::Intake() {
  // Get arm motors
  intakeMotor = Motor::getMotor(intakeMotorPort);
  //armMotor->reverse();
}

void Intake::initDefaultCommand() {
  setDefaultCommand(new StopIntake());
}

/**
 * Move the arm
 * @param left - speed of the left side
 * @param right - speed of the right side
 */
void Intake::move(int speed) {
  //printf("Intake speed is %d\n", speed);
  intakeMotor->getMotorObject()->move_velocity(speed);
}
