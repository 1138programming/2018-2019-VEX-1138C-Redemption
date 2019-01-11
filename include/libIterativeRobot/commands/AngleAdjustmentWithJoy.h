#ifndef _COMMANDS_AngleAdjustmentWithJoy_H_
#define _COMMANDS_AngleAdjustmentWithJoy_H_

#include "libIterativeRobot/commands/Command.h"

class AngleAdjustmentWithJoy: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    AngleAdjustmentWithJoy();
  private:
    int speed;
};

#endif // _COMMANDS_AngleAdjustmentWithJoy_H_
