#ifndef _EVENTS_EVENTSCHEDULER_H_
#define _EVENTS_EVENTSCHEDULER_H_

#include "libIterativeRobot/commands/Command.h"
#include "libIterativeRobot/commands/CommandGroup.h"
#include "main.h"
#include "libIterativeRobot/events/EventListener.h"
#include "libIterativeRobot/subsystems/Subsystem.h"
#include <vector>

namespace libIterativeRobot {

class EventScheduler {
  private:
    size_t numSubsystems = 0; // Keeps track of the number of subsystems on the robot
    static EventScheduler* instance;
    EventScheduler();
    std::vector<Subsystem*> subsystems; // Keeps track of subsystems in order to initialize their default commands
    std::vector<EventListener*> eventListeners; // Keeps track of event listeners
    std::vector<Command*> commandQueue; // Queue for commands that have been added
    std::vector<CommandGroup*> commandGroupQueue; // Queue for command groups that have been added
    std::vector<Command*> commandsToBeAdded;
    std::vector<CommandGroup*> commandGroupsToBeAdded;
    bool defaultAdded = false;
  public:
    const static int millisecondTimeout = 25; // Maximum time to run event listeners
    static EventScheduler* getInstance(); // Return the singleton instance of the event scheduler
    void update(); // Checks event listeners and runs, finishes, and interrupts commands and command groups
    void addEventListener(EventListener* eventListener); // Adds an event listener to keep track of
    void addCommand(Command* commandToRun); // Adds a command to the command queue
    void addCommandGroup(CommandGroup* commandGroupToRun); // Adds a command group to the command group queue
    void queueCommands(); // Adds commands in the commandsToBeAdded vector into the commandQueue
    void queueCommandGroups(); // Adds command groups in the commandGroupsToBeAdded vector into the commandGroupQueue
    void removeCommand(Command* commandToRemove); // Removes a command from the command queue and calls its interrupted function
    void removeCommandGroup(CommandGroup* commandGroupToRemove); // Removes a command from the command group queue and calls its interrupted function
    void trackSubsystem(Subsystem* aSubsystem); // Adds a subsystem to the subsystems vector
    bool commandInQueue(Command* aCommand); // Checks if a command is in the command queue
    bool commandGroupInQueue(CommandGroup* aCommandGroup); // Checks if a command is in the command group queue
    void initialize();
};

};

#endif // _EVENTS_EVENTSCHEDULER_H_
