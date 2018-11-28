#ifndef _COMMANDS_DRIVETOPOSITION_H_
#define _COMMANDS_DRIVETOPOSITION_H_

#include "libIterativeRobot/commands/Command.h"

class DriveToPosition : public libIterativeRobot::Command {
  private:
    double leftTarget;
    double rightTarget;
    double motorSpeed;

    int endTime;
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    DriveToPosition(int leftTarget, int rightTarget, int motorSpeed);
    DriveToPosition(int leftTarget, int rightTarget);
};

#endif // _COMMANDS_DRIVETOPOSITION_H_
