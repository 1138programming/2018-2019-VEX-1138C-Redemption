#ifndef _COMMANDS_MOVECAPFLIPPER180DEGREES_H_
#define _COMMANDS_MOVECAPFLIPPER180DEGREES_H_

#include "libIterativeRobot/commands/Command.h"

class MoveCapFlipper180Degrees: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    MoveCapFlipper180Degrees();
  private:
    unsigned int startTime;
};

#endif // _COMMANDS_MOVECAPFLIPPER180DEGREES_H_
