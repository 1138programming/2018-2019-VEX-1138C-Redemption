#ifndef _COMMANDS_COLLECTORFORWARDTIMED_H_
#define _COMMANDS_COLLECTORFORWARDTIMED_H_

#include "libIterativeRobot/commands/Command.h"

class CollectorForwardTimed : public libIterativeRobot::Command {
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
    CollectorForwardTimed(int mSecs);
};

#endif // _COMMANDS_COLLECTORFORWARDTIMED_H_
