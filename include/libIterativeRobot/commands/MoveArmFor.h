#ifndef _COMMANDS_MOVEARMFOR_H_
#define _COMMANDS_MOVEARMFOR_H_

#include "libIterativeRobot/commands/Command.h"

class MoveArmFor: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    MoveArmFor(unsigned int duration, int speed = 127);
  private:
    unsigned int duration;
    unsigned int speed;
    unsigned int startTime;
};

#endif // _COMMANDS_MOVEARMFOR_H_
