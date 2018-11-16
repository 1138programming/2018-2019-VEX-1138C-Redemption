#ifndef _COMMANDS_MOVECLAWFOR_H_
#define _COMMANDS_MOVECLAWFOR_H_

#include "libIterativeRobot/commands/Command.h"

class MoveClawFor: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    MoveClawFor(unsigned int duration, int speed = 127);
  private:
    unsigned int duration;
    int speed;
    unsigned int startTime;
};

#endif // _COMMANDS_MOVECLAWFOR_H_
