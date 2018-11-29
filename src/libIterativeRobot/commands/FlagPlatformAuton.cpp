#include "libIterativeRobot/commands/FlagPlatformAuton.h"
#include "libIterativeRobot/commands/MoveCapFlipperFor.h"
#include "libIterativeRobot/commands/DriveToPosition.h"
#include "libIterativeRobot/commands/MoveIntakeFor.h"
#include "libIterativeRobot/commands/MovePuncherFor.h"

FlagPlatformAuton::FlagPlatformAuton() {

  addSequentialCommand(new DriveToPosition(0, -0, 127)); // Drive, TODO delete this is if it not needed.
  addParallelCommand(new MoveIntakeFor(1000, -127)); // Prime
  addSequentialCommand(new MovePuncherFor(1000)); // PuncherShoot
  addSequentialCommand(new DriveToPosition(100, -100, 127));

}
