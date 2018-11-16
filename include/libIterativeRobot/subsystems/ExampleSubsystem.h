#ifndef _SUBSYSTEMS_EXAMPLESUBSYSTEM_H_
#define _SUBSYSTEMS_EXAMPLESUBSYSTEM_H_

#include "./Subsystem.h"

class ExampleSubsystem : public libIterativeRobot::Subsystem {
  public:
    void initDefaultCommand();
    ExampleSubsystem();
};

#endif // _SUBSYSTEMS_EXAMPLESUBSYSTEM_H_
