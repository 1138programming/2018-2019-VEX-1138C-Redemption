#ifndef _SUBSYSTEMS_TUSK_H_
#define _SUBSYSTEMS_TUSK_H_

#include "./Subsystem.h"
#include "Constants.h"
#include "api.h"

class Tusk : public libIterativeRobot::Subsystem {
  private:
    // Arm motors
    Motor* tuskMotor1;

    //PIDController* armController;

  public:
    void initDefaultCommand();
    void move(int speed);
    bool tuskAtTarget();
    Tusk();
};

#endif // _SUBSYSTEMS_TUSK_H_
