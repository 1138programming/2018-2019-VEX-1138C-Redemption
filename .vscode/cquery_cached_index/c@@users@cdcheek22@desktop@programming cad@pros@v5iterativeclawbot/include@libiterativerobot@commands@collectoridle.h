#ifndef _COMMANDS_COLLECTORIDLE_H_
#define _COMMANDS_COLLECTORIDLE_H_

#include "libIterativeRobot/commands/Command.h"

class CollectorIdle : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    CollectorIdle();
};

#endif // _COMMANDS_COLLECTORIDLE_H_
