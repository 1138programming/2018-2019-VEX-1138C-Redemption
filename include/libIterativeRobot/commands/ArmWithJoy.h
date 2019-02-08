#ifndef _COMMANDS_ARMWITHJOY_H_
#define _COMMANDS_ARMEWITHJOY_H_

#include "libIterativeRobot/commands/Command.h"

class ArmWithJoy: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    ArmWithJoy();
  private:
    int armSpeed;

};

#endif // _COMMANDS_DRIVEWITHJOY_H_
