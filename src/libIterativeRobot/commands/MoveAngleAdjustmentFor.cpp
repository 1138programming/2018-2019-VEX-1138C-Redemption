// #include "libIterativeRobot/commands/MoveAngleAdjustmentFor.h"
// #include "libIterativeRobot/Robot.h"
// #include "Constants.h"
//
// MoveAngleAdjustmentFor::MoveAngleAdjustmentFor(unsigned int duration, int speed) {
//   this->duration = duration;
//   this->speed = speed;
//
//   requires(Robot::angleAdjustment);
//   this->priority = 1;
// }
//
// bool MoveAngleAdjustmentFor::canRun() {
//   return true; // This is the default value anyways, so this method can be removed
// }
//
// void MoveAngleAdjustmentFor::initialize() {
//   // Perform any initialization steps for this command here, not in the
//   // constructor
//   printf("Initiating move angleAdjustment\n");
//   startTime = pros::millis();
// }
//
// void MoveAngleAdjustmentFor::execute() {
//   Robot::angleAdjustment->move(speed);
// }
//
// bool MoveAngleAdjustmentFor::isFinished() {
//   return pros::millis() > (startTime + duration);
// }
//
// void MoveAngleAdjustmentFor::end() {
//   // Code that runs when isFinished() returns true.
//   Robot::angleAdjustment->move(0);
// }
//
// void MoveAngleAdjustmentFor::interrupted() {
//   // Code that runs when this command is interrupted by another one
//   // with a higher priority.
//   Robot::angleAdjustment->move(0);
// }
