#include "libIterativeRobot/Robot.h"
#include "libIterativeRobot/events/EventScheduler.h"
#include "libIterativeRobot/events/JoystickButton.h"
#include "libIterativeRobot/events/JoystickChannel.h"

#include "libIterativeRobot/commands/StopBase.h"
#include "libIterativeRobot/commands/StopCapFlipper.h"
#include "libIterativeRobot/commands/CapFlipperControlForward.h"
#include "libIterativeRobot/commands/CapFlipperControlBackward.h"
#include "libIterativeRobot/commands/MoveCapFlipperFor.h"
#include "libIterativeRobot/commands/DriveWithJoy.h"
#include "libIterativeRobot/commands/MovePuncherFor.h"
#include "libIterativeRobot/commands/PuncherControl.h"
#include "libIterativeRobot/commands/StopPuncher.h"
#include "libIterativeRobot/commands/StopIntake.h"
#include "libIterativeRobot/commands/MoveIntakeFor.h"
#include "libIterativeRobot/commands/IntakeControlIn.h"
#include "libIterativeRobot/commands/IntakeControlOut.h"
#include "libIterativeRobot/commands/MoveCapFlipper180Degrees.h"

#include "libIterativeRobot/commands/FlagPlatformAuton.h"

Base*  Robot::base = 0;
CapFlipper*   Robot::capFlipper = 0;
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
  capFlipper  = new CapFlipper();
  puncher = new Puncher();
  intake = new Intake();
  //claw = new Claw();

  autonChooser = AutonChooser::getInstance();

  mainController = new pros::Controller(pros::E_CONTROLLER_MASTER);
  partnerController = new pros::Controller(pros::E_CONTROLLER_PARTNER);

  // Define buttons and channels
  libIterativeRobot::JoystickChannel* RightY = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  libIterativeRobot::JoystickChannel* LeftY = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_LEFT_Y);
  libIterativeRobot::JoystickButton* CapFlipperForward = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_R1);
  libIterativeRobot::JoystickButton* CapFlipperBackward = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_R2);
  libIterativeRobot::JoystickButton* PuncherShoot = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_UP);
  libIterativeRobot::JoystickButton* PuncherPrime = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_DOWN);
  libIterativeRobot::JoystickButton* IntakeIn = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_L2);
  libIterativeRobot::JoystickButton* IntakeOut = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_L1);
  libIterativeRobot::JoystickButton* IntakeRotation = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_X);
  libIterativeRobot::JoystickButton* CapFlipperFull = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_Y);


  // Add commands to be run to buttons
  DriveWithJoy* driveCommand = new DriveWithJoy();
  RightY->whilePastThreshold(driveCommand);
  LeftY->whilePastThreshold(driveCommand);



  CapFlipperForward->whileHeld(new CapFlipperControlForward());
  CapFlipperBackward->whileHeld(new CapFlipperControlBackward());
  CapFlipperFull->whenPressed(new MoveCapFlipper180Degrees());

  PuncherShoot->whileHeld(new PuncherControl());
  PuncherPrime->whenPressed(new MovePuncherFor(750));

  IntakeIn->whileHeld(new IntakeControlIn());
  IntakeOut->whileHeld(new IntakeControlOut());
  IntakeRotation->whenPressed(new MoveIntakeFor(750));

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
      printf("Running group %d\n", 2);
      autonGroup = new FlagPlatformAuton();
      break;
  }
  autonGroup->run();
}

void Robot::autonPeriodic() {
  //printf("Default autonPeriodic() function\n");
  libIterativeRobot::EventScheduler::getInstance()->update();
  Motor::periodicUpdate();
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
