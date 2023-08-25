#include "main.h"
#include "pros/imu.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"

 pros::Imu potentiometer(9);

//Helper Functions
void setDrive(int left, int right) {
    frontLeftDrive = left;
    middleLeftDrive = left;
    backLeftDrive = left;
    frontRightDrive = right;
    middleRightDrive = right;
    backRightDrive = right;
}

void resetDriveEncoders() {
 frontLeftDrive.tare_position();
 middleLeftDrive.tare_position();
 backLeftDrive.tare_position();
 frontRightDrive.tare_position();
 middleRightDrive.tare_position();
 backRightDrive.tare_position();
}

double avgDriveEncoderValue() {
    return fabs(frontLeftDrive.get_position()) + 
    fabs(middleLeftDrive.get_position()) + 
    fabs(backLeftDrive.get_position()) + 
    fabs(frontRightDrive.get_position()) + 
    fabs(middleRightDrive.get_position()) + 
    fabs(backRightDrive.get_position()) / 6;
}

//Driver Control
void setDriveMotors() {
    int leftJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rightJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    if(abs(leftJoystick) < 10)
        leftJoystick = 0;
    if(abs(rightJoystick) < 10)
        rightJoystick = 0;
    setDrive(leftJoystick, rightJoystick);
}

//Autonomous
//Gyro Based Movement

void translate(int units, int voltage) {
    //Define a Direction Based on Units Given
    int direction = abs(units) / units;
    //Reset Motor Encoders and Potentiometer
    resetDriveEncoders();
    potentiometer.reset();
    //Drive Until Units Are Reached
    while(avgDriveEncoderValue() < abs(units)) {
        setDrive(voltage * direction +  potentiometer.get_rotation(), voltage * direction -  potentiometer.get_rotation());
        pros::delay(10);
    }
    //Brief Brake
    setDrive(-10 * direction, -10 * direction);
    pros::delay(50);
    //Set Drive To Neutral
    setDrive(0, 0);
}

//Non Gyro Based Movement

// void translate(int units, int voltage) {
//     //Define a Direction Based on Units Given
//     int direction = abs(units) / units;
//     //Reset Motor Encoders
//     resetDriveEncoders();
//     //Drive Until Units Are Reached
//     while(avgDriveEncoderValue() < abs(units)) {
//         setDrive(voltage * direction, voltage * direction);
//         pros::delay(10);
//     }
//     //Brief Brake
//     setDrive(-10 * direction, -10 * direction);
//     pros::delay(50);
//     //Set Drive To Neutral
//     setDrive(0, 0);
// }

//Gyro Based Turns

void rotate(int degree, int voltage) {
    //Define a Direction
    int direction = abs(degree) / degree;
    //Reset Gyro
    potentiometer.reset();
    resetDriveEncoders();
    //Turn * 10???
    setDrive(-voltage * direction, voltage * direction);
    while(fabs(potentiometer.get_rotation()) < abs(degree)) {
        pros::delay(10);
    }
    //Correction
   pros::delay(100);
   if(fabs(potentiometer.get_rotation()) > abs(degree) - 0 /*subtract normal overshoot*/) {
        setDrive(voltage * direction, -voltage * direction);
        while(fabs(potentiometer.get_rotation()) > abs(degree)) {
        pros::delay(10);
    }
   }
    //Reset Drive to 0
    setDrive(0, 0);
}


//Base Turn Function With Gyro

// void rotate(int degree, int voltage) {
//     //Define a Direction
//     int direction = abs(degree) / degree;
//     //Reset Gyro
//     potentiometer.reset();
//     resetDriveEncoders();
//     //Turn * 10???
//     while(fabs(potentiometer.get_rotation()) < abs(degree)) {
//         setDrive(-voltage * direction, voltage * direction);
//         pros::delay(10);
//     }
//     //Brief Brake
//     setDrive(10 * direction, -10 * direction);
//     //Reset Drive to 0
//     setDrive(0, 0);
// }