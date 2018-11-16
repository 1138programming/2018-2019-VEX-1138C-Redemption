#ifndef _COMMANDS_BASETOGGLE_H_
#define _COMMANDS_BASETOGGLE_H_

#include "libIterativeRobot/commands/Command.h"

class BaseToggle : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    BaseToggle();
};

#endif // _COMMANDS_BASETOGGLE_H_
