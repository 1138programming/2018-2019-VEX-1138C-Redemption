#ifndef _COMMANDS_INTAKECONTROLOUT_H_
#define _COMMANDS_INTAKECONTROLOUT_H_

#include "libIterativeRobot/commands/Command.h"

class IntakeControlOut: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    IntakeControlOut();
  private:
};

#endif // _COMMANDS_INTAKECONTROLOUT_H_
