#ifndef _SUBSYSTEMS_BEATER_H_
#define _SUBSYSTEMS_BEATER_H_

#include "./Subsystem.h"
#include "api.h"
#include "abstractBaseClasses/Motor.h"

class Beater : public libIterativeRobot::Subsystem {
  private:
    Motor* beaterMotor;
  public:
    void initDefaultCommand();
    void runBeater(int velocity);
    Beater();
};

#endif // _SUBSYSTEMS_BEATER_H_
