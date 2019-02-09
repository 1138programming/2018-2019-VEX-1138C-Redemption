#include "libIterativeRobot/commands/TwoFlagAuton.h"
#include "libIterativeRobot/commands/MoveAngleAdjustmentFor.h"
#include "libIterativeRobot/commands/DriveToPosition.h"
#include "libIterativeRobot/commands/MoveIntakeFor.h"
#include "libIterativeRobot/commands/MovePuncherFor.h"

TwoFlagAuton::TwoFlagAuton() {
  addSequentialCommand(new DriveToPosition(2800, 2800)); // Forward to the cap // 2000 for red, 2300 for blue
  addParallelCommand(new MovePuncherFor(200)); // PuncherShoot
  addParallelCommand(new MoveIntakeFor(2500));
  addSequentialCommand(new DriveToPosition(-2650, -2650, 125));
  addParallelCommand(new MoveIntakeFor(500));


  addSequentialCommand(new DriveToPosition(-650, 650, 60)); // Forward to the cap // 2000 for red, 2300 for blue
// Stuff
  addSequentialCommand(new DriveToPosition(450, 450, 100)); // Rotate a bit // +,- for red
  addSequentialCommand(new DriveToPosition(50, 50, 25)); // Rotate a bit // +,- for red
  addParallelCommand(new MovePuncherFor(1000)); // PuncherShoot

  addSequentialCommand(new DriveToPosition(890, 890, 100)); // Forward to the wall
  addParallelCommand(new MoveIntakeFor(2000));
  addSequentialCommand(new DriveToPosition(50, 50, 50)); // Forward to the wall
  addParallelCommand(new MovePuncherFor(1000)); // PuncherShoot
  addSequentialCommand(new DriveToPosition(-40, 40, 50)); // Forward to the wall
  addSequentialCommand(new DriveToPosition(2500, 2500)); // Forward to the wall

  addSequentialCommand(new DriveToPosition(-3500, -3500)); // Forward to the cap // 2000 for red, 2300 for blue

}
