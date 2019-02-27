#include "libIterativeRobot/Robot.h"
#include "libIterativeRobot/events/EventScheduler.h"
#include "libIterativeRobot/events/JoystickButton.h"
#include "libIterativeRobot/events/JoystickChannel.h"

#include "libIterativeRobot/commands/StopBase.h"
#include "libIterativeRobot/commands/StopTusk.h"
#include "libIterativeRobot/commands/TuskControlUp.h"
#include "libIterativeRobot/commands/TuskControlDown.h"
#include "libIterativeRobot/commands/MoveTuskFor.h"
#include "libIterativeRobot/commands/DriveWithJoy.h"
#include "libIterativeRobot/commands/MovePuncherFor.h"
#include "libIterativeRobot/commands/PuncherControl.h"
#include "libIterativeRobot/commands/StopPuncher.h"
#include "libIterativeRobot/commands/StopIntake.h"
#include "libIterativeRobot/commands/MoveIntakeFor.h"
#include "libIterativeRobot/commands/IntakeControlIn.h"
#include "libIterativeRobot/commands/IntakeControlOut.h"
#include "libIterativeRobot/commands/TuskWithJoy.h"
#include "libIterativeRobot/commands/StopArm.h"
#include "libIterativeRobot/commands/ArmWithJoy.h"
#include "libIterativeRobot/commands/MoveArmForward.h"
#include "libIterativeRobot/commands/MoveArmBackward.h"


#include "libIterativeRobot/commands/TwoFlagAuton.h"
#include "libIterativeRobot/commands/TwoFlagAutonBlue.h"
#include "libIterativeRobot/commands/FlagPlatformAuton.h"
#include "libIterativeRobot/commands/FlagPlatformAutonBlue.h"
#include "libIterativeRobot/commands/FrontTile.h"
#include "libIterativeRobot/commands/FinalAutonRed.h"
#include "libIterativeRobot/commands/FinalAutonBlue.h"

Base*  Robot::base = 0;
Tusk*   Robot::tusk = 0;
Puncher*   Robot::puncher = 0;
Intake*   Robot::intake = 0;
Arm* Robot::arm = 0;

AutonChooser* Robot::autonChooser = 0;

pros::Controller* Robot::mainController = 0;
pros::Controller* Robot::partnerController = 0;

Robot::Robot() {
  printf("Overridden robot constructor!\n");
  autonGroup = NULL;
  // Initialize any subsystems
  base = new Base();
  tusk  = new Tusk();
  puncher = new Puncher();
  intake = new Intake();
  arm = new Arm();
  //claw = new Claw();

  autonChooser = AutonChooser::getInstance();

  mainController = new pros::Controller(pros::E_CONTROLLER_MASTER);
  partnerController = new pros::Controller(pros::E_CONTROLLER_PARTNER);

  // Define buttons and channels
  libIterativeRobot::JoystickChannel* RightY = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  libIterativeRobot::JoystickChannel* LeftY = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_LEFT_Y);
  libIterativeRobot::JoystickChannel* RightX = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_RIGHT_X);
  libIterativeRobot::JoystickChannel* LeftX = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_LEFT_X);
  //libIterativeRobot::JoystickButton* tuskControlPosition1 = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_DOWN);
  //libIterativeRobot::JoystickButton* tuskControlPosition2= new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_UP);
  libIterativeRobot::JoystickButton* PuncherShoot = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_RIGHT);
  libIterativeRobot::JoystickButton* PuncherPrime = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_LEFT);
  libIterativeRobot::JoystickButton* IntakeOut = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_L2);
  libIterativeRobot::JoystickButton* IntakeIn = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_L1);
  libIterativeRobot::JoystickButton* GoPuncher = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_R1);
  libIterativeRobot::JoystickButton* TuskUp = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_A);
  libIterativeRobot::JoystickButton* TuskDown = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_X);

  DriveWithJoy* driveCommand = new DriveWithJoy();
  //TuskWithJoy* tuskCommand = new TuskWithJoy();
  // ArmWithJoy* armWithJoy = new ArmWithJoy();
  // Add commands to be run to buttons

  RightY->whilePastThreshold(driveCommand);
  //RightY->whilePastThreshold(armWithJoy);
  LeftY->whilePastThreshold(driveCommand);
  //LeftX->whilePastThreshold(driveCommand);

  PuncherShoot->whileHeld(new PuncherControl());
  PuncherPrime->whenPressed(new MovePuncherFor(750));
  GoPuncher->whileHeld(new PuncherControl());

  //tuskControlPosition1->whenPressed(new MoveTuskFor(750));
  //tuskControlPosition2->whenPressed(new MoveTuskFor(750));

  IntakeIn->whileHeld(new IntakeControlIn());
  IntakeOut->whileHeld(new IntakeControlOut());

  TuskUp->whileHeld(new MoveArmForward());
  TuskDown->whileHeld(new MoveArmBackward());

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
      autonGroup = new TwoFlagAuton();
      break;
    case 1:
      printf("Running group %d\n", 1);
      autonGroup = new TwoFlagAutonBlue();
      break;
    case 2:
      printf("Running groupd %d\n", 2);
      autonGroup = new FlagPlatformAuton();
      break;
    case 3:
      printf("Running group %d\n", 3);
      autonGroup = new FlagPlatformAutonBlue();
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
