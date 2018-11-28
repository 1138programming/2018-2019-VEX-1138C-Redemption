#ifndef _COMMANDS_INTAKECONTROLIN_H_
#define _COMMANDS_INTAKECONTROLIN_H_

#include "libIterativeRobot/commands/Command.h"

class IntakeControlIn: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    IntakeControlIn();
  private:
};

#endif // _COMMANDS_INTAKECONTROLIN_H_
