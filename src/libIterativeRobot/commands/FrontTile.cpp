#include "libIterativeRobot/commands/FrontTile.h"
#include "libIterativeRobot/commands/MoveCapFlipperFor.h"
#include "libIterativeRobot/commands/DriveToPosition.h"
#include "libIterativeRobot/commands/MoveIntakeFor.h"
#include "libIterativeRobot/commands/MovePuncherFor.h"

FrontTile::FrontTile() {
  // 1250 is one tile forward
  //addParallelCommand(new MoveIntakeFor(1000, -200)); // Prime
  addSequentialCommand(new MovePuncherFor(1000)); // PuncherShoot
  addSequentialCommand(new DriveToPosition(3300, 3300)); // Forward to the cap
  addSequentialCommand(new DriveToPosition(-3700, -3700)); // Forward to the cap

}
