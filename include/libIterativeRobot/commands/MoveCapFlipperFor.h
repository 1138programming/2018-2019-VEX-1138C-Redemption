#ifndef _COMMANDS_MOVECAPFLIPPERFOR_H_
#define _COMMANDS_MOVECAPFLIPPERFOR_H_

#include "libIterativeRobot/commands/Command.h"

class MoveCapFlipperFor: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    MoveCapFlipperFor(unsigned int duration, int speed = 127);
  private:
    unsigned int duration;
    unsigned int speed;
    unsigned int startTime;
};

#endif // _COMMANDS_MOVECAPFLIPPERFOR_H_
