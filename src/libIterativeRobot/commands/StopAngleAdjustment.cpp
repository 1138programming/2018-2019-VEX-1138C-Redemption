// #include "libIterativeRobot/commands/StopAngleAdjustment.h"
// #include "libIterativeRobot/Robot.h"
// #include "Constants.h"
//
// StopAngleAdjustment::StopAngleAdjustment() {
//   requires(Robot::angleAdjustment);
//   this->priority = DefaultCommandPriority; // Lowest priority
// }
//
// bool StopAngleAdjustment::canRun() {
//   return true; // This is the default value anyways, so this method can be removed
// }
// 
// void StopAngleAdjustment::initialize() {
//   // Perform any initialization steps for this command here, not in the
//   // constructor
//   Robot::angleAdjustment->move(0);
// }
//
// void StopAngleAdjustment::execute() {
//   Robot::angleAdjustment->move(0);
//   //printf("Stopping angleAdjustment\n");
// }
//
// bool StopAngleAdjustment::isFinished() {
//   return true;
// }
//
// void StopAngleAdjustment::end() {
//   // Code that runs when isFinished() returns true.
// }
//
// void StopAngleAdjustment::interrupted() {
//   // Code that runs when this command is interrupted by another one
//   // with a higher priority.
// }
