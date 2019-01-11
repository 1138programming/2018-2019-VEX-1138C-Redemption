#ifndef _COMMANDS_MOVEANGLEADJUSTMENTFOR_H_
#define _COMMANDS_MOVEANGLEADJUSTMENTFOR_H_

#include "libIterativeRobot/commands/Command.h"

class MoveAngleAdjustmentFor: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    MoveAngleAdjustmentFor(unsigned int duration, int speed = 127);
  private:
    unsigned int duration;
    unsigned int speed;
    unsigned int startTime;
};

#endif // _COMMANDS_MOVEANGLEADJUSTMENTFOR_H_
