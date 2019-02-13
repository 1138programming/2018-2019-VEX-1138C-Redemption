#include "abstractBaseClasses/Motor.h"

Motor* Motor::motorInstances[MAX_MOTORS];
const pros::motor_gearset_e_t Motor::defaultGearset = pros::E_MOTOR_GEARSET_18;
const pros::motor_encoder_units_e_t Motor::defaultEncoderUnits = pros::E_MOTOR_ENCODER_COUNTS;

Motor::Motor(std::uint8_t channel) {
  // Determine whether the motor is a v5 or v4 motor based on what port it is in
  if (channel >= 97) {
    channel -= 32;
  }
  if (channel >= 65) {
    channel -= 16;
  }
  if (channel >= 49) {
    channel -= 21;
  }

  this->channel = channel;

  if (channel <= 21)
    motorType = v5;
  else
    motorType = v4;

  // Set defaults
  gearset = defaultGearset;
  encoderUnits = defaultEncoderUnits;
  speed = 0;
  slewedSpeed = 0;
  slewStep = defaultSlewStep;
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

void Motor::setMaster(Motor* motor) {
  // Set a master motor
  following = true;
  master = motor;
}

void Motor::setSpeed(int speed) {
  // Sets the speed of the motor
  // If this motor is a follower, setSpeed does nothing
  if (following)
    return;

  this->speed = speed * multiplier;

  // Confine speed to between -127 to 127
  //speed = threshold((int)(confineToRange(speed, -KMaxMotorSpeed, KMaxMotorSpeed) * multiplier), this->threshold);

  // Set the speed of the follower motors to the same speed
  for (unsigned int i = 0; i < numFollowers; i++) {
      if (followers[i] != NULL) {
        followers[i]->speed = speed * followers[i]->multiplier;
      }
  }
}

void Motor::moveTo(int target, int motorSpeed) {
  if (following) {
    return;
  }

  v5Motor->move_relative(target * (abs(multiplier) / multiplier), motorSpeed);
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
  // Set the v4 encoder. Not used in a v5 motor.
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

int Motor::getSpeed() {
  // Return the speed of the motor
  return following ? master->getSpeed() : speed;
}

int Motor::getChannel() {
  // Return the motor channel
  return channel;
}

std::int32_t Motor::getEncoderValue() {
  // Return v5 encoder value, or a dedicated v4 motor's
  // encoder value if it exists.
  if (this->motorType == v4) {
    if (this->encoder != NULL) {
      return this->encoder->get_value() * abs(multiplier) / multiplier;
    }
  } else {
    return this->v5Motor->get_position() * abs(multiplier) / multiplier;
  }
  return 0;
}

MotorType Motor::getMotorType() {
  // Returns a MotorType, either v4 or v5
  return motorType;
}

void Motor::setSlewStep(int newSlew) {
  slewStep = newSlew;
}

pros::Motor* Motor::getMotorObject() {
  // Return the raw v5 motor object, if needed for any purpose
  return this->v5Motor;
}

// doesn't work
int Motor::updateSlewRate(int targetSpeed) {
  // A bit of motor slewing to make sure that we don't stall
  // https://en.wikipedia.org/wiki/Slew_rate
  int deltaSpeed = targetSpeed - slewedSpeed;
  int sign = deltaSpeed < 0 ? -1 : 1;
  if (abs(deltaSpeed) > slewStep) {
    slewedSpeed += slewStep * sign;
  } else {
    slewedSpeed = targetSpeed;
  }

  return slewedSpeed;
}

void Motor::move() {
  if (motorType == v4)
    v4Motor->set_value(updateSlewRate(speed));
  else
    v5Motor->move_velocity(updateSlewRate(speed));
}

void Motor::periodicUpdate() {
  // Update all the motor speeds, using slew rates if chosen
  for (int i = 0; i < MAX_MOTORS; i++) {
    //motorInstances[i]->updateSlewRate();
    if (motorInstances[i] != NULL) {
      motorInstances[i]->move();
    }
  }
}

Motor* Motor::getMotor(int motorPort) {
  // If the motor exists, return it
  // Otherwise, create it first
  if (motorInstances[motorPort - 1] == NULL) {
    motorInstances[motorPort - 1] = new Motor(motorPort);
    return motorInstances[motorPort - 1];
  } else {
    return motorInstances[motorPort - 1];
  }
}

Motor* Motor::getMotor(Port motorPort) {
  // If the motor exists, return it
  // Otherwise, create it first
  if (motorInstances[motorPort - 1] == NULL) {
    motorInstances[motorPort - 1] = new Motor(motorPort);
    return motorInstances[motorPort - 1];
  } else {
    return motorInstances[motorPort - 1];
  }
}
