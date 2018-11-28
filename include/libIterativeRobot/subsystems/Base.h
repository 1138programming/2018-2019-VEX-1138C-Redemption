#ifndef _SUBSYSTEMS_BASE_H_
#define _SUBSYSTEMS_BASE_H_

#include "./Subsystem.h"
#include "api.h"
#include "Constants.h"

class Base : public libIterativeRobot::Subsystem {
  private:
    // Base motors
    Motor* frontLeftMotor;
    Motor* frontRightMotor;
    Motor* backLeftMotor;
    Motor* backRightMotor;

  public:
    void initDefaultCommand();
    void move(int left, int right);
    void moveBaseTo(int leftTarget, int rightTarget, int motorSpeed=KMaxMotorSpeed);
    bool baseAtTarget();
    Base();
};

#endif // _SUBSYSTEMS_BASE_H_
