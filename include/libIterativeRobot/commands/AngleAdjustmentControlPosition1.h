#ifndef _COMMANDS_AngleAdjustmentControlPosition1_H_
#define _COMMANDS_AngleAdjustmentControlPosition1_H_

#include "libIterativeRobot/commands/Command.h"

class AngleAdjustmentControlPosition1: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    AngleAdjustmentControlPosition1(unsigned int duration, int speed = 200);
    AngleAdjustmentControlPosition1();
  private:
    unsigned int duration;
    unsigned int speed;
    unsigned int startTime;
};

#endif // _COMMANDS_AngleAdjustmentControlPosition1_H_
