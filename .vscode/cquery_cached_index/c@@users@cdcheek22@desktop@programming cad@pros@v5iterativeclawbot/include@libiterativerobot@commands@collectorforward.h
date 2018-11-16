#ifndef _COMMANDS_COLLECTORFORWARD_H_
#define _COMMANDS_COLLECTORFORWARD_H_

#include "libIterativeRobot/commands/Command.h"

class CollectorForward : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    CollectorForward();
};

#endif // _COMMANDS_COLLECTORFORWARD_H_
