#ifndef _COMMANDS_STOPPUNCHER_H_
#define _COMMANDS_STOPPUNCHER_H_

#include "libIterativeRobot/commands/Command.h"

class StopPuncher: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    StopPuncher();
  private:
};

#endif // _COMMANDS_STOPPUNCHER_H_
