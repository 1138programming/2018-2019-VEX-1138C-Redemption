#ifndef _COMMANDS_DRIVEWITHJOYX_H_
#define _COMMANDS_DRIVEWITHJOYX_H_

#include "libIterativeRobot/commands/Command.h"

class DriveWithJoyX: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    DriveWithJoyX();
  private:
    int rightSideSpeed;
    int leftSideSpeed;
};

#endif // _COMMANDS_DRIVEWITHJOYX_H_
