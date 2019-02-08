#ifndef _COMMANDS_MOVEARMBACKWARD_H_
#define _COMMANDS_MOVEARMBACKWARD_H_

#include "libIterativeRobot/commands/Command.h"

class MoveArmBackward: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    MoveArmBackward();
  private:
};

#endif // _COMMANDS_MOVEPUNCHERFOR_H_
