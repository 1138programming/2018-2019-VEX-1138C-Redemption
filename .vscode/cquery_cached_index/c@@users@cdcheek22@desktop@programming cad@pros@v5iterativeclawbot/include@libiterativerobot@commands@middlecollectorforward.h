#ifndef _COMMANDS_MIDDLECOLLECTORFORWARD_H_
#define _COMMANDS_MIDDLECOLLECTORFORWARD_H_

#include "libIterativeRobot/commands/Command.h"

class MiddleCollectorForward : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    MiddleCollectorForward();
};

#endif // _COMMANDS_MIDDLECOLLECTORFORWARD_H_
