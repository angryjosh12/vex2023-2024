#include "main.h"
#include "pros/motors.h"

//Motors
pros::Motor catapult(1, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intake(2, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);

pros::Motor frontLeftDrive(3, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor middleLeftDrive(4, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor backLeftDrive(5, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor frontRightDrive(6, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor middleRightDrive(7, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor backRightDrive(8, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);

//pros::Motor catapult(port, gearset, reversed?t/f, encoderunits);
//pros::E_MOTOR_GEARSET_06 600RPM
//pros::E_MOTOR_GEARSET_18 200RPM  
//pros::E_MOTOR_GEARSET_36 100RPM  

//Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

