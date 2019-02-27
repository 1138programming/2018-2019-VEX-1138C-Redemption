#ifndef _EVENTS_JOYSTICKBUTTON_H_
#define _EVENTS_JOYSTICKBUTTON_H_

#include "main.h"
#include "./Trigger.h"
#include "../commands/Command.h"
#include <vector>

namespace libIterativeRobot {

class JoystickButton : public Trigger {
  private:
    pros::Controller* controller;
    pros::controller_digital_e_t button;
  protected:
  public:
    JoystickButton(pros::Controller* controller, pros::controller_digital_e_t button);
    void whenPressed(Command* command, Action action = RUN); // Sets pressedCommand
    void whileHeld(Command* command, Action action = RUN); // Sets heldCommand
    void whenReleased(Command* command, Action action = RUN); // Sets depressedCommand
    void whileReleased(Command* command, Action action = RUN); // Sets releasedCommand
    bool get();
};

};

#endif // _EVENTS_JOYSTICKBUTTON_H_
