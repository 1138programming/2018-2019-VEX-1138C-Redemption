#ifndef _COMMANDS_DRIVEWITHJOYSTICKS_H_
#define _COMMANDS_DRIVEWITHJOYSTICKS_H_

#include "libIterativeRobot/commands/Command.h"

class DriveWithJoysticks : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    DriveWithJoysticks();
};

#endif // _COMMANDS_DRIVEWITHJOYSTICKS_H_
