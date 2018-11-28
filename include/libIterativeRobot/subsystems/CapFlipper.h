#ifndef _SUBSYSTEMS_CAPFLIPPER_H_
#define _SUBSYSTEMS_CAPFLIPPER_H_

#include "./Subsystem.h"
#include "Constants.h"
#include "api.h"

class CapFlipper : public libIterativeRobot::Subsystem {
  private:
    // Arm motors
    Motor* leftCapFlipper;
    Motor* rightCapFlipper;

    //PIDController* armController;

  public:
    void initDefaultCommand();
    void move(int speed);
    void move180(int speed1 = KMaxMotorSpeed, int speed2 = (int)(KMaxMotorSpeed * 0.8));
    bool capFlipperAtTarget();
    CapFlipper();
};

#endif // _SUBSYSTEMS_CAPFLIPPER_H_
