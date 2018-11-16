#include "libIterativeRobot/commands/DelayCommand.h"
#include "libIterativeRobot/Robot.h"

// ADD TO PROSITERATIVEROBOT

DelayCommand::DelayCommand(int mSecs) {
  runTime = mSecs;
}

bool DelayCommand::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void DelayCommand::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  startTime = pros::millis();
}

void DelayCommand::execute() {
  // Code that runs when this command is scheduled to run
  Robot::robotBase->toggleBaseSpeed();
}

bool DelayCommand::isFinished() {
  return (pros::millis() - startTime) > runTime;; // This is the default va  lue anyways, so this method can be removed
}

void DelayCommand::end() {
  // Code that runs when isFinished() returns true.
}

void DelayCommand::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
