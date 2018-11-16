#include "main.h"
#include "libIterativeRobot/commands/StopArm.h"

Arm::Arm() {
  // Get arm motors
  armMotor = Motor::getMotor(armPort);
  //armMotor->reverse();

  armController = new PIDController(armMotor, 0.32, 0, 0.05);
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
  //printf("Arm speed is %d\n", speed);
  armMotor->setSpeed(speed);
}

void Arm::setSetpoint(int setpoint) {
  armController->setSetpoint(setpoint);
}

bool Arm::atSetpoint() {
  return armController->atSetpoint();
}

void Arm::loop() {
  armController->loop();
}

void Arm::lock() {
  armController->lock();
}

void Arm::disablePID() {
  armController->enabled = false;
}

void Arm::enablePID() {
  armController->enabled = true;
}
