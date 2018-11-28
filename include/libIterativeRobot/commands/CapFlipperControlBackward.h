#ifndef _COMMANDS_CAPFLIPPERCONTROLBACKWARD_H_
#define _COMMANDS_CAPFLIPPERCONTROLBACKWARD_H_

#include "libIterativeRobot/commands/Command.h"

class CapFlipperControlBackward: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    CapFlipperControlBackward();
  private:
};

#endif // _COMMANDS_CAPFLIPPERCONTROLBACKWARD_H_
