#ifndef _SUBSYSTEMS_CLAW_H_
#define _SUBSYSTEMS_CLAW_H_

#include "./Subsystem.h"
#include "api.h"

class Claw : public libIterativeRobot::Subsystem {
  private:
    // Claw motors
    Motor* clawMotor;

  public:
    void initDefaultCommand();
    void move(int speed);
    Claw();
};

#endif // _SUBSYSTEMS_CLAW_H_
