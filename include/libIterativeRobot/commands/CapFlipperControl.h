#ifndef _COMMANDS_CAPFLIPPERCONTROL_H_
#define _COMMANDS_CAPFLIPPERCONTROL_H_

#include "libIterativeRobot/commands/Command.h"

class CapFlipperControl: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    CapFlipperControl(bool Forward);
  private:
    bool Forward;
};

#endif // _COMMANDS_CAPFLIPPERCONTROL_H_
