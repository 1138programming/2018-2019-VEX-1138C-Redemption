#ifndef _COMMANDS_MOVETUSKFOR_H_
#define _COMMANDS_MOVETUSKFOR_H_

#include "libIterativeRobot/commands/Command.h"

class MoveTuskFor: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    MoveTuskFor(unsigned int duration, int speed = 127);
  private:
    unsigned int duration;
    unsigned int speed;
    unsigned int startTime;
};

#endif // _COMMANDS_MOVETUSKFOR_H_
