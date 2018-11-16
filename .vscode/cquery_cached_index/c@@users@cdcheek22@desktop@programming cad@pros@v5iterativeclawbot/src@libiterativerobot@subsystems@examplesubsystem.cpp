#include "main.h"
#include "libIterativeRobot/commands/ExampleCommand.h"

ExampleSubsystem::ExampleSubsystem() {
  // If you want to set a default command to run when this subsystem
  // is idle, uncomment and modify the following line of code:
  // setDefaultCommand(new ExampleCommand());
}

void ExampleSubsystem::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new ExampleCommand());
}
