#ifndef _COMMANDS_PUNCHERCONTROL_H_
#define _COMMANDS_PUNCHERCONTROL_H_

#include "libIterativeRobot/commands/Command.h"

class PuncherControl: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    PuncherControl();
  private:
};

#endif // _COMMANDS_PUNCHERCONTROL_H_
