#ifndef _EVENTS_EVENTLISTENER_H_
#define _EVENTS_EVENTLISTENER_H_

#include "main.h"

namespace libIterativeRobot {

class EventListener {
  private:
  protected:
    virtual void checkConditions() = 0;
  public:
  friend class EventScheduler; // Let the Event Scheduler use the checkConditions() method
};

};

#endif // _EVENTS_EVENTLISTENER_H_
