#ifndef _COMMANDS_CAPFLIPPERWITHJOY_H_
#define _COMMANDS_CAPFLIPPERWITHJOY_H_

#include "libIterativeRobot/commands/Command.h"

class CapFlipperWithJoy: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    CapFlipperWithJoy();
  private:
    int speed;
};

#endif // _COMMANDS_CAPFLIPPERWITHJOY_H_
