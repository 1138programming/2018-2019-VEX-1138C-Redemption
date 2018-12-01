#include "abstractBaseClasses/Motor.h"

Motor* Motor::motorInstances[MAX_MOTORS];
const pros::motor_gearset_e_t Motor::defaultGearset = pros::E_MOTOR_GEARSET_18;
const pros::motor_encoder_units_e_t Motor::defaultEncoderUnits = pros::E_MOTOR_ENCODER_COUNTS;

Motor::Motor(std::uint8_t channel) {
  // Determine whether the motor is a v5 or v4 motor based on what port it is in
  this->channel = channel;
  if (channel <= 21)
    motorType = v5;
  else
    motorType = v4;

  // Set defaults
  gearset = defaultGearset;
  encoderUnits = defaultEncoderUnits;
  speed = 0;
  multiplier = 1;
  following = false;
  master = NULL;

  // Get the motor object
  if (motorType == v4) {
    v4Motor = new pros::ADIMotor(channel);
  } else {
    v5Motor = new pros::Motor(channel, gearset, false, encoderUnits);
  }

  // Initialize all elements in the followers array to null
  numFollowers = MAX_FOLLOWERS;
  for (unsigned int i = 0; i < numFollowers; i++) {
    followers[i] = NULL;
  }
}

// Set a master motor
void Motor::setMaster(Motor* motor) {
  following = true;
  master = motor;
}

// Initialize motorInstances array with motor instances
void Motor::init() {
  for (std::uint8_t i = 0; i < MAX_MOTORS; i++) {
    motorInstances[i] = new Motor(i + 1);
  }
}

Motor* Motor::getMotor(int motorPort) {
  return motorInstances[motorPort - 1];
}

Motor* Motor::getMotor(Port motorPort) {
  return motorInstances[motorPort - 1];
}

// Sets the speed of the motor
void Motor::setSpeed(int speed) {
  // If this motor is a follower, setSpeed does nothing
  if (following)
    return;

  // Confine speed to between -127 to 127
  //speed = threshold((int)(confineToRange(speed, -KMaxMotorSpeed, KMaxMotorSpeed) * multiplier), this->threshold);

  // Set the speed of the follower motors to the same speed
  for (unsigned int i = 0; i < numFollowers; i++) {
      if (followers[i] != NULL) {
        followers[i]->speed = speed;
      }
  }
}

void Motor::setThreshold(int threshold) {
  this->threshold = threshold;
}

void Motor::reverse() {
  multiplier *= -1;
}

void Motor::setMultiplier(float multiplier) {
  this->multiplier = multiplier;
}

void Motor::setEncoder(pros::ADIEncoder* encoder) {
  this->encoder = encoder;
}

void Motor::addFollower(Motor* motor) {
  // Cannot add followers to a follower
  if (following)
    return;

  // Set all of the followers of the follower to null
  for(unsigned int i = 0; i < motor->numFollowers; i++) {
    if (motor->followers[i] != NULL)
      return;
  }

  // Set add the follower to the followers array and set the follower's master to this motor
  for (unsigned int i = 0; i < numFollowers; i++) {
    if (followers[i] == NULL) {
      followers[i] = motor;
      motor->setMaster(this);
      return;
    }
  }
}

// Return the speed of the motor
int Motor::getSpeed() {
  return following ? master->getSpeed() : speed;
}

// Return the motor channel
int Motor::getChannel() {
  return channel;
}

std::int32_t Motor::getEncoderValue() {
  if (this->motorType == v4) {
    if (this->encoder != NULL)
      return this->encoder->get_value();
  } else {
    std::uint32_t time = pros::millis();
    return this->v5Motor->get_raw_position(&time);
  }
  return 0;
}

// Returns a MotorType, either v4 or v5
MotorType Motor::getMotorType() {
  return motorType;
}

pros::Motor* Motor::getMotorObject() {
  return this->v5Motor;
}

// doesn't work
int Motor::updateSlewRate(int targetSpeed) {
  // A bit of motor slewing to make sure that we don't stall
}

void Motor::move() {
  if (motorType == v4)
    v4Motor->set_value(updateSlewRate(speed));
  else
    v5Motor->move(speed);
}

void Motor::periodicUpdate() {
  for (int i = 0; i < MAX_MOTORS; i++) {
    //motorInstances[i]->updateSlewRate();
    motorInstances[i]->move();
  }
}
