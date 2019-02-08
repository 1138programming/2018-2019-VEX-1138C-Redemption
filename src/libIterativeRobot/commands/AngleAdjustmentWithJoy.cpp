// #include "libIterativeRobot/commands/AngleAdjustmentWithJoy.h"
// #include "libIterativeRobot/Robot.h"
// #include "Constants.h"
//
// AngleAdjustmentWithJoy::AngleAdjustmentWithJoy() {
//   requires(Robot::angleAdjustment);
//   this->priority = 2;
// }
//
// bool AngleAdjustmentWithJoy::canRun() {
//   return true; // This is the default value anyways, so this method can be removed
// }
//
// void AngleAdjustmentWithJoy::initialize() {
//   // Perform any initialization steps for this command here, not in the
//   // constructor
//   speed = Robot::mainController->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
// }
//
// void AngleAdjustmentWithJoy::execute() {
//   Robot::angleAdjustment->move(speed);
// }
//
// bool AngleAdjustmentWithJoy::isFinished() {
//   return true;
// }
//
// void AngleAdjustmentWithJoy::end() {
//   // Code that runs when isFinished() returns true.
// }
//
// void AngleAdjustmentWithJoy::interrupted() {
//   // Code that runs when this command is interrupted by another one
//   // with a higher priority.
// }
