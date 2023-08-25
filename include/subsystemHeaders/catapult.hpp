#include "main.h"

//Helper Function
void setCatapult(int power);

void resetCatapultEncoders();

double avgCatapultEncoderValue();

//Driver Control
void setCatapultMotors();

//Autonomous
void catapultRotation(int units, int voltage);