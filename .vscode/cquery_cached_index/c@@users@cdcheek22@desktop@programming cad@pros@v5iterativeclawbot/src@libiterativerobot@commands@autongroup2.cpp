#include "libIterativeRobot/commands/AutonGroup2.h"
#include "libIterativeRobot/commands/MoveClawFor.h"

AutonGroup2::AutonGroup2() {
  addSequentialCommand(new MoveClawFor(1000));
  addSequentialCommand(new MoveClawFor(1000));
}
