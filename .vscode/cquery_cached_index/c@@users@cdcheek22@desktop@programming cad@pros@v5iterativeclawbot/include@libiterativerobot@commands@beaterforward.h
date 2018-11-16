#ifndef _COMMANDS_BEATERFORWARD_H_
#define _COMMANDS_BEATERFORWARD_H_

#include "libIterativeRobot/commands/Command.h"

class BeaterForward : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    BeaterForward();
};

#endif // _COMMANDS_BEATERFORWARD_H_
