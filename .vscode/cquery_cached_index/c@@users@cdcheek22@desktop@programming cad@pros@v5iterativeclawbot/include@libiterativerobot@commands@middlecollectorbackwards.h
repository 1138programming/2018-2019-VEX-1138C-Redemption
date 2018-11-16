#ifndef _COMMANDS_MIDDLECOLLECTORBACKWARDS_H_
#define _COMMANDS_MIDDLECOLLECTORBACKWARDS_H_

#include "libIterativeRobot/commands/Command.h"

class MiddleCollectorBackwards : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    MiddleCollectorBackwards();
};

#endif // _COMMANDS_MIDDLECOLLECTORBACKWARDS_H_
