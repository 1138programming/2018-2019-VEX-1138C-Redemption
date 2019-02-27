#ifndef _COMMANDS_DELAYCOMMAND_H_
#define _COMMANDS_DELAYCOMMAND_H_

#include "libIterativeRobot/commands/Command.h"

class DelayCommand : public libIterativeRobot::Command {
  private:
    int startTime;
    int runTime;
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    DelayCommand(int mSecs);
};

#endif // _COMMANDS_DELAYCOMMAND_H_
