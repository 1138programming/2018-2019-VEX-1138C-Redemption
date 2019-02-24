#ifndef _COMMANDS_STOPTUSK_H_
#define _COMMANDS_STOPTUSK_H_

#include "libIterativeRobot/commands/Command.h"

class StopTusk: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    StopTusk();
  private:
};

#endif // _COMMANDS_STOPTUSK_H_
