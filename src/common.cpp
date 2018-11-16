#include "main.h"
#include "common.h"

int threshold(int aNumber, int threshold) {
	return (abs(aNumber) >= threshold) ? aNumber : 0;
}

// DO NOT USE! Create pin objects in subsystems
bool getLimitSwitch(unsigned char pin) {
	pros::ADIDigitalIn* limitSwitch = new pros::ADIDigitalIn(pin);
	return limitSwitch->get_value();
}

int confineToRange(int value, int min, int max) {
	if (min > max) return confineToRange(value, max, min);
	if (value < min)
		return min;
	else if (value > max)
		return max;
	return value;
}

bool inRange(int value, int min, int max) {
	return min <= value && value <= max;
}

int sign(int aNumber) {
	if (aNumber == 0) return 0;
	return aNumber/abs(aNumber);
}
