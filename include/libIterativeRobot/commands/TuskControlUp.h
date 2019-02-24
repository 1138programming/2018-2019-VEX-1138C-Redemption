#ifndef _COMMANDS_TuskControlUp_H_
#define _COMMANDS_TuskControlUp_H_

#include "libIterativeRobot/commands/Command.h"

class TuskControlUp: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    TuskControlUp();
  private:
};

#endif // _COMMANDS_TuskControlUp_H_
