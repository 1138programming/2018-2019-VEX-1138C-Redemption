#ifndef _COMMANDS_FLYWHEELBACKWARDS_H_
#define _COMMANDS_FLYWHEELBACKWARDS_H_

#include "libIterativeRobot/commands/Command.h"

class FlywheelBackwards : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    FlywheelBackwards();
};

#endif // _COMMANDS_FLYWHEELBACKWARDS_H_
