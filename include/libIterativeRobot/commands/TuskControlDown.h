#ifndef _COMMANDS_TuskControlDown_H_
#define _COMMANDS_TuskControlDown_H_

#include "libIterativeRobot/commands/Command.h"

class TuskControlDown: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    TuskControlDown();
  private:
};

#endif // _COMMANDS_TuskControlDown_H_
