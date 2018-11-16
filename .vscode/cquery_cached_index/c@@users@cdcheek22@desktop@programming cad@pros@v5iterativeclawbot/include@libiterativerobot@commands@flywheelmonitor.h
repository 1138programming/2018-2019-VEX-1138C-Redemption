#ifndef _COMMANDS_FLYWHEELMONITOR_H_
#define _COMMANDS_FLYWHEELMONITOR_H_

#include "libIterativeRobot/commands/Command.h"

class FlywheelMonitor : public libIterativeRobot::Command {
  private:
    int lastTime;
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    FlywheelMonitor();
};

#endif // _COMMANDS_FLYWHEELMONITOR_H_
