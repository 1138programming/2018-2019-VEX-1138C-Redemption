#ifndef _COMMANDS_COLLECTORBACKWARDS_H_
#define _COMMANDS_COLLECTORBACKWARDS_H_

#include "libIterativeRobot/commands/Command.h"

class CollectorBackwards : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    CollectorBackwards();
};

#endif // _COMMANDS_COLLECTORBACKWARDS_H_
