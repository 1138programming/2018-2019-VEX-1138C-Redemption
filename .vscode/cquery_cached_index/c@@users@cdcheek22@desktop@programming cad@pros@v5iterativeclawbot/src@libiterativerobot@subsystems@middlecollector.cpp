#include "libIterativeRobot/subsystems/MiddleCollector.h"
#include "libIterativeRobot/commands/MiddleCollectorIdle.h"

MiddleCollector::MiddleCollector() {
  middleCollectorMotor = Motor::getMotor(middleCollectorMotorPort);
  // Slaving will be tested after initial test
}

void MiddleCollector::runMiddleCollector(int velocity) {
  middleCollectorMotor->getMotorObject()->move_velocity(velocity);
}

void MiddleCollector::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new MiddleCollectorIdle());
}
