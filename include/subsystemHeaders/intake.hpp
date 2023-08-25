#include "main.h"

//Helper Function
void setIntake(int power);

void resetIntakeEncoders();

double avgIntakeEncoderValue();

//Driver Control
void setIntakeMotors();

//Autonomous
void intakeRotation(int units, int voltage);