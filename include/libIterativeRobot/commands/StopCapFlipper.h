#ifndef _COMMANDS_STOPCAPFLIPPER_H_
#define _COMMANDS_STOPCAPFLIPPER_H_

#include "libIterativeRobot/commands/Command.h"

class StopCapFlipper: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    StopCapFlipper();
  private:
};

#endif // _COMMANDS_STOPCAPFLIPPER_H_
