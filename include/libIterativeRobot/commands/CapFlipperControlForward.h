#ifndef _COMMANDS_CAPFLIPPERCONTROLFORWARD_H_
#define _COMMANDS_CAPFLIPPERCONTROLFORWARD_H_

#include "libIterativeRobot/commands/Command.h"

class CapFlipperControlForward: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    CapFlipperControlForward();
  private:
};

#endif // _COMMANDS_CAPFLIPPERCONTROLFORWARD_H_
