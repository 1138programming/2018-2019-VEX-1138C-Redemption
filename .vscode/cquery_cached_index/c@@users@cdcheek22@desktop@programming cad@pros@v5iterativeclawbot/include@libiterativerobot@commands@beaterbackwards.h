#ifndef _COMMANDS_BEATERBACKWARDS_H_
#define _COMMANDS_BEATERBACKWARDS_H_

#include "libIterativeRobot/commands/Command.h"

class BeaterBackwards : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    BeaterBackwards();
};

#endif // _COMMANDS_BEATERBACKWARDS_H_
