#ifndef _COMMANDS_MOVEARMFORWARD_H_
#define _COMMANDS_MOVEARMFORWARD_H_

#include "libIterativeRobot/commands/Command.h"

class MoveArmForward: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    MoveArmForward();
  private:
};

#endif // _COMMANDS_MOVEPUNCHERFOR_H_
