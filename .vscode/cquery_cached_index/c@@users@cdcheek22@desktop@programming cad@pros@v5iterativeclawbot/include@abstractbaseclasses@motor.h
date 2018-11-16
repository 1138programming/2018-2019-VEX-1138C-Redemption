#ifndef MOTOR_H
#define MOTOR_H

#include "api.h"
#include "Constants.h"
#include "common.h"

enum Port {
  A = 22,
  B,
  C,
  D,
  E,
  F,
  G,
  H,
};

enum MotorType {
  v4,
  v5,
};

class Motor {
  private:
    const static int defaultSlewStep = 14;

    std::uint8_t channel; // Motor channel
    pros::motor_gearset_e_t gearset; // v5 motor gearset
    pros::motor_encoder_units_e_t encoderUnits; // v5 motor encoder units

    int currSpeed; // Used by updateSlew Rate
    int speed; // Speed of the motor
    int slewedSpeed;
    int slewStep;
    float multiplier; // Applied to speed
    int threshold = 5;

    Motor* followers[MAX_FOLLOWERS]; // Array containing the motor's followers
    unsigned int numFollowers; // Number of followers
    Motor* master; // Pointer to master motor
    bool following; // True if the motor is a follower, false otherwise
    void setMaster(Motor* motor); // Sets a motor to be a master motor

    MotorType motorType; // Type of motor
    pros::Motor* v5Motor; // Pointer to v5 motor object
    pros::ADIMotor* v4Motor; // Pointer to v4 motor object
    pros::ADIEncoder* encoder; // Pointer to encoder object for v4 motors

    static Motor* motorInstances[MAX_MOTORS]; // Array of all motor instances
    static const pros::motor_gearset_e_t defaultGearset; // Default gear set is 18, 200 rpm
    static const pros::motor_encoder_units_e_t defaultEncoderUnits; // Default encoder units are counts, or encoder ticks

    Motor(std::uint8_t channel); // Constructor, takes a channel
  public:
    // These functions are used to initialize and access the motor object
    static void init(); // Initializes motor objects
    static Motor* getMotor(int motorPort); // Gets a motor on the specified port, between ports 1-22
    static Motor* getMotor(Port motorPort); // Gets a motor on the specified port, between ports A-H

    // These functions change something about the motor object
    void setSpeed(int speed); // Sets the speed of the motor
    void setThreshold(int threshold); // Sets a threshold for the motor's speed
    void reverse(); // Reverses the motor
    void setMultiplier(float multiplier); // Sets a multiplier to apply to the motor's speed
    void setEncoder(pros::ADIEncoder* encoder); // Sets an encoder to be used for v4 motors in place of a built in encoder
    void addFollower(Motor* motor); // Adds a follower to the motor

    // These functions get something from the motor object
    int getSpeed(); // Gets the last speed set
    int getTheshold(); // Gets the motor's threshold
    int getChannel(); // Gets the motor's channel
    std::int32_t getEncoderValue(); // Gets the encoder value of the motor
    MotorType getMotorType(); // Gets the type of motor

    pros::Motor* getMotorObject();

    // These functions are called repeatedly, updating the motor object
    int updateSlewRate(int targetSpeed); // Doesn't work
    void move(); // Applies the current speed to the motor
    static void periodicUpdate(); // Updates all motors. Calls the move function on all motors
};

#endif
