#ifndef _SUBSYSTEMS_FLYWHEEL_H_
#define _SUBSYSTEMS_FLYWHEEL_H_

#include "./Subsystem.h"
#include "api.h"
#include "abstractBaseClasses/Motor.h"

class Flywheel : public libIterativeRobot::Subsystem {
  private:
    Motor* flywheelMotor;
  public:
    void initDefaultCommand();
    void setFlywheel(int velocity);
    double getFlywheelTemperature();
    double getFlywheelVelocity();
    Flywheel();
};

#endif // _SUBSYSTEMS_FLYWHEEL_H_
