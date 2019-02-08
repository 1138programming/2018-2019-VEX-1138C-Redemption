#ifndef _SUBSYSTEMS_ARM_H_
#define _SUBSYSTEMS_ARM_H_

#include "./Subsystem.h"
#include "api.h"

class Arm : public libIterativeRobot::Subsystem {
  private:
    // Arm motors
    Motor* armMotor;

    //PIDController* armController;

  public:
    void initDefaultCommand();
    bool armAtTarget();
    void move(int speed);
    Arm();
};

#endif // _SUBSYSTEMS_PUNCHER_H_
