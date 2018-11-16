#ifndef _COMMANDS_DRIVEWITHJOY_H_
#define _COMMANDS_DRIVEWITHJOY_H_

#include "libIterativeRobot/commands/Command.h"

class DriveWithJoy: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    DriveWithJoy();
  private:
    int rightSideSpeed;
    int leftSideSpeed;
};

#endif // _COMMANDS_DRIVEWITHJOY_H_
