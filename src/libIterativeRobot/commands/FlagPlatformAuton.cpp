#include "libIterativeRobot/commands/FlagPlatformAuton.h"
#include "libIterativeRobot/commands/MoveCapFlipperFor.h"
#include "libIterativeRobot/commands/DriveToPosition.h"
#include "libIterativeRobot/commands/MoveIntakeFor.h"
#include "libIterativeRobot/commands/MovePuncherFor.h"

FlagPlatformAuton::FlagPlatformAuton() {

  addSequentialCommand(new DriveToPosition(0, -0, 127));
  addParallelCommand(new MoveIntakeFor(1000, -127));
  addSequentialCommand(new MovePuncherFor(1000));

}
