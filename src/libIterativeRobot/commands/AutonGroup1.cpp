#include "libIterativeRobot/commands/AutonGroup1.h"
#include "libIterativeRobot/commands/MoveArmFor.h"

AutonGroup1::AutonGroup1() {
  addSequentialCommand(new MoveArmFor(1000));
  addSequentialCommand(new MoveArmFor(1000));
}
