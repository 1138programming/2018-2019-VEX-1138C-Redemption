#ifndef _COMMANDS_FLYWHEELFORWARD_H_
#define _COMMANDS_FLYWHEELFORWARD_H_

#include "libIterativeRobot/commands/Command.h"

class FlywheelForward : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    FlywheelForward();
};

#endif // _COMMANDS_FLYWHEELFORWARD_H_
