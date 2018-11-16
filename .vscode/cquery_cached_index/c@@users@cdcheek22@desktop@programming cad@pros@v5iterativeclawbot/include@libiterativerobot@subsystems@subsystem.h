#ifndef _SUBSYSTEMS_SUBSYSTEM_H_
#define _SUBSYSTEMS_SUBSYSTEM_H_

#include "main.h"

namespace libIterativeRobot {

class Command;

class Subsystem {
  private:
    Command* defaultCommand = NULL;
  protected:
    /**
      * Set the default command for this subsystem. Should only be called in initDefaultCommand()
      *
      * @param aCommand a Command* to the new default command
      */
    void setDefaultCommand(Command* aCommand);
  public:
    /**
      * Initializes the default command. This should be the only place setDefaultCommand() is called.
      */
    virtual void initDefaultCommand();
    static size_t instances;
    /**
      * Get this subsystem's default command.
      *
      * @return This subsystem's default command
      */
    Command* getDefaultCommand();
    Command* currentCommand = NULL;
    Subsystem();
};

};

#endif // _SUBSYSTEMS_SUBSYSTEM_H_
