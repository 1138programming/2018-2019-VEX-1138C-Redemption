#ifndef _COMMANDS_FLYWHEELREVUP_H_
#define _COMMANDS_FLYWHEELREVUP_H_

#include "libIterativeRobot/commands/Command.h"

class FlywheelRevUp : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    FlywheelRevUp();
};

#endif // _COMMANDS_FLYWHEELREVUP_H_
