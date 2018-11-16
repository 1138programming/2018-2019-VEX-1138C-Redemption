#include "libIterativeRobot/commands/AutonGroup4.h"
#include "libIterativeRobot/commands/DriveToPosition.h"
#include "libIterativeRobot/commands/FlywheelRevUp.h"
#include "libIterativeRobot/commands/DelayCommand.h"
#include "libIterativeRobot/commands/CollectorMiddleForwardTimed.h"
#include "libIterativeRobot/commands/CollectorForwardTimed.h"

AutonGroup4::AutonGroup4() {
  // Bottom and middle flag
    addSequentialCommand(new FlywheelRevUp());
    addSequentialCommand(new DriveToPosition(1800, -1800));
    addSequentialCommand(new DelayCommand(150));
    addSequentialCommand(new CollectorMiddleForwardTimed(500));
    addSequentialCommand(new DelayCommand(150));

    addSequentialCommand(new DriveToPosition(3050, -3050));
    //addSequentialCommand(new DelayCommand(500));
    addSequentialCommand(new DelayCommand(150));


    addSequentialCommand(new DriveToPosition(-3050, 3050));
    //addSequentialCommand(new DriveToPosition(950, 950));
    //addSequentialCommand(new DriveToPosition(3500, -3500, 200));

}
