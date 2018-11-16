#ifndef _SUBSYSTEMS_ARM_H_
#define _SUBSYSTEMS_ARM_H_

#include "./Subsystem.h"
#include "api.h"

class Arm : public libIterativeRobot::Subsystem {
  private:
    // Arm motors
    Motor* armMotor;

    PIDController* armController;

  public:
    void initDefaultCommand();
    void move(int speed);
    void setSetpoint(int setpoint);
    bool atSetpoint();
    void loop();
    void lock();
    void disablePID();
    void enablePID();
    Arm();
};

#endif // _SUBSYSTEMS_ARM_H_
