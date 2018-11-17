#ifndef _COMMANDS_STOPINTAKE_H_
#define _COMMANDS_STOPINTAKE_H_

#include "libIterativeRobot/commands/Command.h"

class StopIntake: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    StopIntake();
  private:
};

#endif // _COMMANDS_STOPINTAKE_H_
