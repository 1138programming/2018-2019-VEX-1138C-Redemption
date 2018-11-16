#ifndef _COMMANDS_COLLECTORMIDDLEFORWARDTIMED_H_
#define _COMMANDS_COLLECTORMIDDLEFORWARDTIMED_H_

#include "libIterativeRobot/commands/Command.h"

class CollectorMiddleForwardTimed : public libIterativeRobot::Command {
  private:
    int runTime; // Time, in milliseconds, to run
    int startTime; // Starting time of this command
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    CollectorMiddleForwardTimed(int mSecs);
};

#endif // _COMMANDS_COLLECTORMIDDLEFORWARDTIMED_H_
