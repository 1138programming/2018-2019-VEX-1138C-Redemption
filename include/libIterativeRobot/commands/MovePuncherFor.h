#ifndef _COMMANDS_MOVEPUNCHERFOR_H_
#define _COMMANDS_MOVEPUNCHERFOR_H_

#include "libIterativeRobot/commands/Command.h"

class MovePuncherFor: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    MovePuncherFor(unsigned int duration, int speed = 127);
  private:
    unsigned int duration;
    unsigned int speed;
    unsigned int startTime;
};

#endif // _COMMANDS_MOVEPUNCHERFOR_H_
