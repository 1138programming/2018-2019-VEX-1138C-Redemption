#include "libIterativeRobot/commands/AutonGroup1.h"
#include "libIterativeRobot/commands/MoveCapFlipperFor.h"

AutonGroup1::AutonGroup1() {
  addSequentialCommand(new MoveCapFlipperFor(1000));
  addSequentialCommand(new MoveCapFlipperFor(1000));
}
