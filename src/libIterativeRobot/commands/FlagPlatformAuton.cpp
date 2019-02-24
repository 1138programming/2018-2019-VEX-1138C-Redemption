#include "libIterativeRobot/commands/FlagPlatformAuton.h"
#include "libIterativeRobot/commands/MoveTuskFor.h"
#include "libIterativeRobot/commands/DriveToPosition.h"
#include "libIterativeRobot/commands/MoveIntakeFor.h"
#include "libIterativeRobot/commands/MovePuncherFor.h"

FlagPlatformAuton::FlagPlatformAuton() {
  //addParallelCommand(new MoveIntakeFor(1000, -200)); // Prime
  addSequentialCommand(new MovePuncherFor(1000)); // PuncherShoot
  addSequentialCommand(new DriveToPosition(410, -410)); // Rotate a bit // +,- for red
  addSequentialCommand(new DriveToPosition(3300, 3300)); // Forward to the cap

  addParallelCommand(new MoveIntakeFor(1500, 200)); // Prime
  addSequentialCommand(new DriveToPosition(-600, -600)); // Forward to the cap
  addSequentialCommand(new DriveToPosition(-700, +700)); // Rotate a bit // -,+ for red

  addSequentialCommand(new DriveToPosition(2000, 2000)); // Forward to the cap // 2000 for red, 2300 for blue

}
