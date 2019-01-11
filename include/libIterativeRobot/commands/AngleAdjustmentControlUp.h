#ifndef _COMMANDS_AngleAdjustmentControlUp_H_
#define _COMMANDS_AngleAdjustmentControlUp_H_

#include "libIterativeRobot/commands/Command.h"

class AngleAdjustmentControlUp: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    AngleAdjustmentControlUp();
  private:
};

#endif // _COMMANDS_AngleAdjustmentControlUp_H_
