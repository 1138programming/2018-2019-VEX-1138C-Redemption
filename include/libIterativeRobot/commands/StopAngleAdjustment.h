#ifndef _COMMANDS_STOPANGLEADJUSTMENT_H_
#define _COMMANDS_STOPANGLEADJUSTMENT_H_

#include "libIterativeRobot/commands/Command.h"

class StopAngleAdjustment: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    StopAngleAdjustment();
  private:
};

#endif // _COMMANDS_STOPANGLEADJUSTMENT_H_
