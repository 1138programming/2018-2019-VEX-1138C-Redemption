#ifndef _SUBSYSTEMS_CAPFLIPPER_H_
#define _SUBSYSTEMS_CAPFLIPPER_H_

#include "./Subsystem.h"
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
    CapFlipper();
};

#endif // _SUBSYSTEMS_CAPFLIPPER_H_
