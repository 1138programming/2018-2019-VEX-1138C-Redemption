#ifndef _ROBOT_H_
#define _ROBOT_H_

#include "main.h"
#include "RobotBase.h"
#include "subsystems/Base.h"
#include "commands/CommandGroup.h"

class Robot : public libIterativeRobot::RobotBase {
  private:
    static lv_res_t print(lv_obj_t* roller);
  protected:
    void robotInit();
    void autonInit();
    void autonPeriodic();
    void teleopInit();
    void teleopPeriodic();
    void disabledInit();
    void disabledPeriodic();
  public:
    Robot();

    // Pointers to every subsystem on the robot:
    static Base* base;
    static Arm*  arm;
    static Claw* claw;

    static AutonChooser* autonChooser;

    libIterativeRobot::CommandGroup* autonGroup = NULL;

    // Pointers to controllers
    static pros::Controller* mainController;
    static pros::Controller* partnerController;
};


#endif // _ROBOT_H_
