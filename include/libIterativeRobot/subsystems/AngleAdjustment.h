#ifndef _SUBSYSTEMS_ANGLEADJUSTMENT_H_
#define _SUBSYSTEMS_ANGLEADJUSTMENT_H_

#include "./Subsystem.h"
#include "Constants.h"
#include "api.h"

class AngleAdjustment : public libIterativeRobot::Subsystem {
  private:
    // Arm motors
    Motor* angleAdjustmentMotor;

    //PIDController* armController;

  public:
    void initDefaultCommand();
    void move(int speed);
    void move180(bool part, int speed1 = KMaxMotorSpeed, int speed2 = (int)(KMaxMotorSpeed * 0.8));
    bool angleAdjustmentAtTarget();
    AngleAdjustment();
};

#endif // _SUBSYSTEMS_ANGLEADJUSTMENT_H_
