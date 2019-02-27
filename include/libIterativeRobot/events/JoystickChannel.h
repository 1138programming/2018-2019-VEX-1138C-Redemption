#ifndef _EVENTS_JOYSTICKCHANNEL_H_
#define _EVENTS_JOYSTICKCHANNEL_H_

#include "api.h"
#include "main.h"
#include "./Trigger.h"
#include "../commands/Command.h"

namespace libIterativeRobot {

class JoystickChannel : public Trigger {
  private:
    pros::Controller* controller;
    pros::controller_analog_e_t channel; // The channel to check
    std::int32_t threshold = kDefaultThreshold; // The treshold for the joystick value
  protected:
  public:
    static const std::int32_t kDefaultThreshold = 10; // Default threshold
    JoystickChannel(pros::Controller* controller, pros::controller_analog_e_t channel);
    void whenPassingThresholdForward(Command* command, Action action = RUN);
    void whilePastThreshold(Command* command, Action action = RUN);
    void whenPassingThresholdReverse(Command* command, Action action = RUN);
    void whileWithinThreshold(Command* command, Action action = RUN);
    void setThreshold(std::int32_t threshold);
    bool get();
};

};

#endif // _EVENTS_JOYSTICKCHANNEL_H_
