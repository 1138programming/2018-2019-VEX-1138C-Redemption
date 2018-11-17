#include "main.h"
#include "libIterativeRobot/commands/StopPuncher.h"

Puncher::Puncher() {
  // Get arm motors
  puncherMotor = Motor::getMotor(puncherMotorPort);
  //armMotor->reverse();
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
