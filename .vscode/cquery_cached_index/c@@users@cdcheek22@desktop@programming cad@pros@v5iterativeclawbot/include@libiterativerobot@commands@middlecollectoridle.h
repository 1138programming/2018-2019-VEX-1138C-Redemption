#ifndef _COMMANDS_MIDDLECOLLECTORIDLE_H_
#define _COMMANDS_MIDDLECOLLECTORIDLE_H_

#include "libIterativeRobot/commands/Command.h"

class MiddleCollectorIdle : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    MiddleCollectorIdle();
};

#endif // _COMMANDS_MIDDLECOLLECTORIDLE_H_
