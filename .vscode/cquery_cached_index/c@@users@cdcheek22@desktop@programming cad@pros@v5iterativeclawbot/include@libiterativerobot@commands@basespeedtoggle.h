#ifndef _COMMANDS_BASESPEEDTOGGLE_H_
#define _COMMANDS_BASESPEEDTOGGLE_H_

#include "libIterativeRobot/commands/Command.h"

class BaseSpeedToggle : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    BaseSpeedToggle();
};

#endif // _COMMANDS_BASESPEEDTOGGLE_H_
