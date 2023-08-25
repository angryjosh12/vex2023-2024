#include "main.h"

//Helper Functions
void setDrive(int left, int right);

void resetDriveEncoders();

double avgDriveEncoderValue();

//Driver Control
void setDriveMotors();

//Autonomous
void translate(int units, int voltage);

void rotate(int degree, int voltage);