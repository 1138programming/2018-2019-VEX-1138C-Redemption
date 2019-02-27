#ifndef _EVENTS_TRIGGER_H_
#define _EVENTS_TRIGGER_H_

#include "main.h"
#include "./EventListener.h"
#include "../commands/Command.h"
#include <vector>

namespace libIterativeRobot {

enum Action {
  RUN,
  STOP,
};

class Trigger : public EventListener {
  private:
    bool lastState = false; // Keeps track of the last state of the button being checked

    std::vector<Command*> runWhenActivatedCommands;
    std::vector<Command*> runWhileActiveCommands;
    std::vector<Command*> runWhenDeactivatedCommands;
    std::vector<Command*> runWhileInactiveCommands;

    std::vector<Command*> stopWhenActivatedCommands;
    std::vector<Command*> stopWhileActiveCommands;
    std::vector<Command*> stopWhenDeactivatedCommands;
    std::vector<Command*> stopWhileInactiveCommands;
  protected:
    Trigger();
    void checkConditions(); // Checks the trigger's conditions and decides which, if any, commands to run or cancel
    void whenActivated(Command* command, Action action = RUN); // Adds a command to be run when the trigger is activated
    void whileActive(Command* command, Action action = RUN); // Adds a command to be run while the trigger is active
    void whenDeactivated(Command* command, Action action = RUN); // Adds a command to be run when the trigger is deactivated
    void whileInactive(Command* command, Action action = RUN); // Adds a command to be run while the trigger is inactive
  public:
    virtual bool get() = 0;
};

};

#endif // _EVENTS_TRIGGER_H_
