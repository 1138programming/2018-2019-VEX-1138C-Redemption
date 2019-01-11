#ifndef _COMMANDS_AngleAdjustmentControlDown_H_
#define _COMMANDS_AngleAdjustmentControlDown_H_

#include "libIterativeRobot/commands/Command.h"

class AngleAdjustmentControlDown: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    AngleAdjustmentControlDown();
  private:
};

#endif // _COMMANDS_AngleAdjustmentControlDown_H_
