#ifndef _COMMANDS_BEATERIDLE_H_
#define _COMMANDS_BEATERIDLE_H_

#include "libIterativeRobot/commands/Command.h"

class BeaterIdle : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    BeaterIdle();
};

#endif // _COMMANDS_BEATERIDLE_H_
