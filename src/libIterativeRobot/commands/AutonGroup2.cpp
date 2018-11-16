#include "libIterativeRobot/commands/AutonGroup2.h"
#include "libIterativeRobot/commands/MoveCapFlipperFor.h"

AutonGroup2::AutonGroup2() {
  addSequentialCommand(new MoveCapFlipperFor(1000));
}
