#include "libIterativeRobot/commands/FlywheelMonitor.h"
#include "libIterativeRobot/Robot.h"

FlywheelMonitor::FlywheelMonitor() {
  requires(Robot::flywheel);
  lastTime = 0;
  //Robot::mainController->print(0, 0, "RPM: %f", Robot::flywheel->getFlywheelVelocity());
}

bool FlywheelMonitor::canRun() {
  return pros::millis() > (lastTime + 1500); // This is the default value anyways, so this method can be removed
}

void FlywheelMonitor::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  lastTime = pros::millis();
}

void FlywheelMonitor::execute() {
  // Code that runs when this command is scheduled to run
  //Robot::mainController->set_text(0, 0, "Flywheel");
  //Robot::mainController->clear();
  Robot::mainController->print(0, 0, "RPM: %f", Robot::flywheel->getFlywheelVelocity());
  //Robot::mainController->print(2, 0, "Temp: %f", Robot::flywheel->getFlywheelTemperature());
}

bool FlywheelMonitor::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void FlywheelMonitor::end() {
  // Code that runs when isFinished() returns true.
}

void FlywheelMonitor::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
