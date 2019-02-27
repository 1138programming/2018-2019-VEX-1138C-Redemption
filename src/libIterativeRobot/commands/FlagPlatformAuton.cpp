#include "libIterativeRobot/commands/FlagPlatformAuton.h"
#include "libIterativeRobot/commands/MoveTuskFor.h"
#include "libIterativeRobot/commands/DriveToPosition.h"
#include "libIterativeRobot/commands/MoveIntakeFor.h"
#include "libIterativeRobot/commands/MovePuncherFor.h"
#include "libIterativeRobot/commands/DelayCommand.h"

FlagPlatformAuton::FlagPlatformAuton() {
  addSequentialCommand(new DelayCommand(6500));
  addSequentialCommand(new MoveIntakeFor(1000, -200)); // Prime
  addSequentialCommand(new MovePuncherFor(1000)); // PuncherShoot
  addSequentialCommand(new DriveToPosition(370, -370)); // Rotate a bit // +,- for red
  addSequentialCommand(new DriveToPosition(3300, 3300)); // Forward to the cap

  addParallelCommand(new MoveIntakeFor(3300, 200)); // Prime
  addSequentialCommand(new DriveToPosition(-650, -650)); // Forward to the cap
  addSequentialCommand(new DriveToPosition(600, -600)); // Rotate a bit // +,- for red

  addSequentialCommand(new DriveToPosition(-3000, -3000)); // Forward to the cap // 3000 for red, 3000 for blue

}
