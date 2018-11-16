#ifndef _EVENTS_JOYSTICKCHANNEL_H_
#define _EVENTS_JOYSTICKCHANNEL_H_

#include "api.h"
#include "main.h"
#include "./EventListener.h"
#include "../commands/Command.h"

namespace libIterativeRobot {

// Enum for joystick channels
/*enum Channels {
  ChRightY=1,
  ChRightX,
  ChLeftY,
  ChLeftX,
};*/

class JoystickChannel : public EventListener {
  private:
    pros::Controller* controller;
    pros::controller_analog_e_t channel; // The channel to check
    int threshold = kDefaultThreshold; // The treshold for the joystick value
    Command* pastThresholdCommand = NULL; // Command or command group run if the joystick value is past the threshold
  protected:
    virtual void checkConditions();
  public:
    static const std::int32_t kDefaultThreshold = 10; // Default threshold
    JoystickChannel(pros::Controller* controller, pros::controller_analog_e_t channel);
    void whilePastThreshold(Command* pastThresholdCommand, std::int32_t threshold = kDefaultThreshold);
};

};

#endif // _EVENTS_JOYSTICKCHANNEL_H_
