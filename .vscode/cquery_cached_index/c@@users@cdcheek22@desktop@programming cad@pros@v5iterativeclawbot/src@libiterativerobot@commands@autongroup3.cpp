#include "libIterativeRobot/commands/AutonGroup3.h"
#include "libIterativeRobot/commands/DriveToPosition.h"
#include "libIterativeRobot/commands/FlywheelRevUp.h"
#include "libIterativeRobot/commands/DelayCommand.h"
#include "libIterativeRobot/commands/CollectorMiddleForwardTimed.h"
#include "libIterativeRobot/commands/CollectorForwardTimed.h"

AutonGroup3::AutonGroup3() {
    addSequentialCommand(new FlywheelRevUp());
    addSequentialCommand(new CollectorMiddleForwardTimed(500));
    addSequentialCommand(new DelayCommand(150));

    addSequentialCommand(new DriveToPosition(3050, -3050));
    //addSequentialCommand(new DelayCommand(500));
    addSequentialCommand(new DelayCommand(150));

    addSequentialCommand(new DriveToPosition(-4850, 4850));
    addSequentialCommand(new DriveToPosition(950, 950));
    addSequentialCommand(new DriveToPosition(6500, -6500, 200));
}
