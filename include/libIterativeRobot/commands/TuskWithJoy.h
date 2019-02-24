#ifndef _COMMANDS_TuskWithJoy_H_
#define _COMMANDS_TuskWithJoy_H_

#include "libIterativeRobot/commands/Command.h"

class TuskWithJoy: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    TuskWithJoy();
  private:
    int speed;
};

#endif // _COMMANDS_TuskWithJoy_H_
