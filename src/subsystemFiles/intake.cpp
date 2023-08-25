#include "main.h"
#include "pros/misc.h"

//Helper Function
void setIntake(int power) {
    intake = power;
}

void resetIntakeEncoders() {
 intake.tare_position();
}

double avgIntakeEncoderValue() {
    return fabs(intake.get_position())  / 1;
}

//DriverControl
void setIntakeMotors() {
    int intakePower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));
    setIntake(intakePower);
}

//Autonomous
void intakeRotation(int units, int voltage) {
    //Define a Direction Based on Units Given
    int direction = abs(units) / units;
    //Reset Motor Encoders
    resetIntakeEncoders();
    //Drive Until Units Are Reached
    while(avgIntakeEncoderValue() < abs(units)) {
        setIntake(voltage * direction);
        pros::delay(10);
    }
    //Brief Brake
    setIntake(-10 * direction);
    pros::delay(50);
    //Set Drive To Neutral
    setIntake(0);
}