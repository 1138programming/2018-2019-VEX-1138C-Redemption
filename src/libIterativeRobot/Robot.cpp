#include "libIterativeRobot/Robot.h"
#include "libIterativeRobot/events/EventScheduler.h"
#include "libIterativeRobot/events/JoystickButton.h"
#include "libIterativeRobot/events/JoystickChannel.h"

#include "libIterativeRobot/commands/StopBase.h"
#include "libIterativeRobot/commands/StopAngleAdjustment.h"
#include "libIterativeRobot/commands/AngleAdjustmentControlUp.h"
#include "libIterativeRobot/commands/AngleAdjustmentControlDown.h"
#include "libIterativeRobot/commands/AngleAdjustmentControlPosition1.h"
#include "libIterativeRobot/commands/AngleAdjustmentControlPosition2.h"
#include "libIterativeRobot/commands/MoveAngleAdjustmentFor.h"
#include "libIterativeRobot/commands/DriveWithJoy.h"
#include "libIterativeRobot/commands/MovePuncherFor.h"
#include "libIterativeRobot/commands/PuncherControl.h"
#include "libIterativeRobot/commands/StopPuncher.h"
#include "libIterativeRobot/commands/StopIntake.h"
#include "libIterativeRobot/commands/MoveIntakeFor.h"
#include "libIterativeRobot/commands/IntakeControlIn.h"
#include "libIterativeRobot/commands/IntakeControlOut.h"
#include "libIterativeRobot/commands/AngleAdjustmentWithJoy.h"

#include "libIterativeRobot/commands/FlagPlatformAuton.h"
#include "libIterativeRobot/commands/FlagPlatformAutonBlue.h"
#include "libIterativeRobot/commands/FrontTile.h"

Base*  Robot::base = 0;
AngleAdjustment*   Robot::angleAdjustment = 0;
Puncher*   Robot::puncher = 0;
Intake*   Robot::intake = 0;

AutonChooser* Robot::autonChooser = 0;

pros::Controller* Robot::mainController = 0;
pros::Controller* Robot::partnerController = 0;

Robot::Robot() {
  printf("Overridden robot constructor!\n");
  autonGroup = NULL;
  // Initialize any subsystems
  base = new Base();
  angleAdjustment  = new AngleAdjustment();
  puncher = new Puncher();
  intake = new Intake();
  //claw = new Claw();

  autonChooser = AutonChooser::getInstance();

  mainController = new pros::Controller(pros::E_CONTROLLER_MASTER);
  partnerController = new pros::Controller(pros::E_CONTROLLER_PARTNER);

  // Define buttons and channels
  libIterativeRobot::JoystickChannel* RightY = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  libIterativeRobot::JoystickChannel* LeftY = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_LEFT_Y);
  libIterativeRobot::JoystickChannel* RightX = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_RIGHT_X);
  libIterativeRobot::JoystickChannel* LeftX = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_LEFT_X);
  libIterativeRobot::JoystickButton* angleAdjustmentControlPosition1 = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_DOWN);
  libIterativeRobot::JoystickButton* angleAdjustmentControlPosition2= new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_UP);
  libIterativeRobot::JoystickButton* PuncherShoot = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_R1);
  libIterativeRobot::JoystickButton* PuncherPrime = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_R2);
  libIterativeRobot::JoystickButton* IntakeOut = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_L2);
  libIterativeRobot::JoystickButton* IntakeIn = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_L1);

  DriveWithJoy* driveCommand = new DriveWithJoy();
  AngleAdjustmentWithJoy* angleAdjustmentCommand = new AngleAdjustmentWithJoy();
  // Add commands to be run to buttons

  RightY->whilePastThreshold(angleAdjustmentCommand);
  LeftY->whilePastThreshold(driveCommand);
  LeftX->whilePastThreshold(driveCommand);

  PuncherShoot->whileHeld(new PuncherControl());
  PuncherPrime->whenPressed(new MovePuncherFor(750));

  angleAdjustmentControlPosition1->whenPressed(new AngleAdjustmentControlPosition1(750));
  angleAdjustmentControlPosition2->whenPressed(new AngleAdjustmentControlPosition2(750));

  IntakeIn->whileHeld(new IntakeControlIn());
  IntakeOut->whileHeld(new IntakeControlOut());

  //ClawOpen->whileHeld(new ClawControl(true));
  //ClawClose->whileHeld(new ClawControl(false));

}

void Robot::robotInit() {
  printf("Robot created.\n");
}

void Robot::autonInit() {
  printf("Default autonInit() function\n");
  libIterativeRobot::EventScheduler::getInstance()->initialize();
  autonChooser->uninit();

  switch (autonChooser->getAutonChoice()) {
    case 0:
      printf("Running group %d\n", 1);
      autonGroup = new FlagPlatformAuton();
      break;
    case 1:
      printf("Running group %d\n", 1);
      autonGroup = new FlagPlatformAutonBlue();
      break;
    case 2:
      printf("Running group %d\n", 2);
      autonGroup = new FrontTile();
      break;
  }
  autonGroup->run();
}

void Robot::autonPeriodic() {
  //printf("Default autonPeriodic() function\n");
  libIterativeRobot::EventScheduler::getInstance()->update();
  //Motor::periodicUpdate();
  //PIDController::loopAll();
}

lv_res_t Robot::print(lv_obj_t* roller) {
  char* optionName = new char[128]();
  lv_roller_get_selected_str(roller, optionName);
  printf("Option selected is called ");
  printf(optionName);
  printf("\n");
  return LV_RES_OK;
}

void Robot::teleopInit() {
  printf("Default teleopInit() function\n");
  libIterativeRobot::EventScheduler::getInstance()->initialize();
  autonChooser->init();
}

void Robot::teleopPeriodic() {
  //printf("Default teleopPeriodic() function\n");
  libIterativeRobot::EventScheduler::getInstance()->update();
  Motor::periodicUpdate();
  //PIDController::loopAll();
}

void Robot::disabledInit() {
  printf("Default disabledInit() function\n");
  libIterativeRobot::EventScheduler::getInstance()->initialize();
  autonChooser->uninit();
}

void Robot::disabledPeriodic() {
  //printf("Default disabledPeriodic() function\n");
}
