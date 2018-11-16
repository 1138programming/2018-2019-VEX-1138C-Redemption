#include "libIterativeRobot/commands/AutonGroup2.h"
#include "libIterativeRobot/commands/MoveArmTo.h"

AutonGroup2::AutonGroup2() {
  addSequentialCommand(new MoveArmTo(1000));
}
