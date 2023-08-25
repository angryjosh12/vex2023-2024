#include "main.h"
#include "pros/misc.h"

//Helper Function
void setCatapult(int power) {
    catapult = power;
}

void resetCatapultEncoders() {
 catapult.tare_position();
}

double avgCatapultEncoderValue() {
    return fabs(catapult.get_position())  / 1;
}

//DriverControl
void setCatapultMotors() {
    int catapultPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
    setCatapult(catapultPower);
}

//Autonomous
void catapultRotation(int units, int voltage) {
    //Define a Direction Based on Units Given
    int direction = abs(units) / units;
    //Reset Motor Encoders
    resetCatapultEncoders();
    //Drive Until Units Are Reached
    while(avgCatapultEncoderValue() < abs(units)) {
        setCatapult(voltage * direction);
        pros::delay(10);
    }
    //Brief Brake
    setCatapult(-10 * direction);
    pros::delay(50);
    //Set Drive To Neutral
    setCatapult(0);
}