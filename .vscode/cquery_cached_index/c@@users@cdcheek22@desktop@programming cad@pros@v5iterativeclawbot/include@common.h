#include "Constants.h"

#ifndef _COMMON_H_
#define _COMMON_H_

int threshold(int aNumber, int threshold = 20);

bool getLimitSwitch(unsigned char pin);

int confineToRange(int value, int min = -KMaxMotorSpeed, int max = KMaxMotorSpeed);

bool inRange(int value, int min = -KMaxMotorSpeed, int max = KMaxMotorSpeed);

int sign(int aNumber);

//float fabs(float value);

#endif
