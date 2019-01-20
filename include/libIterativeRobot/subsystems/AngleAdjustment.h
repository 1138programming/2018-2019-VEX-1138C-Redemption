#ifndef _SUBSYSTEMS_ANGLEADJUSTMENT_H_
#define _SUBSYSTEMS_ANGLEADJUSTMENT_H_

#include "./Subsystem.h"
#include "Constants.h"
#include "api.h"

class AngleAdjustment : public libIterativeRobot::Subsystem {
  private:
    // Arm motors
    Motor* angleAdjustmentMotor1;
    Motor* angleAdjustmentMotor2;

    //PIDController* armController;

  public:
    void initDefaultCommand();
    void move(int speed);
    bool angleAdjustmentAtTarget();
    AngleAdjustment();
};

#endif // _SUBSYSTEMS_ANGLEADJUSTMENT_H_
