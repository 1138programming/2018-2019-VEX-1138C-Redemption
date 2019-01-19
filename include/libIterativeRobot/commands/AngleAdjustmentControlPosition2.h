#ifndef _COMMANDS_AngleAdjustmentControlPosition2_H_
#define _COMMANDS_AngleAdjustmentControlPosition2_H_

#include "libIterativeRobot/commands/Command.h"

class AngleAdjustmentControlPosition2: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    AngleAdjustmentControlPosition2(unsigned int duration, int speed = 200);
    AngleAdjustmentControlPosition2();
  private:
    unsigned int duration;
    unsigned int speed;
    unsigned int startTime;
};

#endif // _COMMANDS_AngleAdjustmentControlPosition1_H_
