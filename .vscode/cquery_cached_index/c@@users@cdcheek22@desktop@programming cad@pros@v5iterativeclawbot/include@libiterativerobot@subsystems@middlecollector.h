#ifndef _SUBSYSTEMS_MIDDLECOLLECTOR_H_
#define _SUBSYSTEMS_MIDDLECOLLECTOR_H_

#include "./Subsystem.h"
#include "api.h"
#include "abstractBaseClasses/Motor.h"

class MiddleCollector : public libIterativeRobot::Subsystem {
  private:
    Motor* middleCollectorMotor;
  public:
    void initDefaultCommand();
    void runMiddleCollector(int velocity);
    MiddleCollector();
};

#endif // _SUBSYSTEMS_MIDDLECOLLECTOR_H_
