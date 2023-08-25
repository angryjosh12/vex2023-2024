#include "main.h"
#include "display/lv_core/lv_obj.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"

int redLeftSideButton = 0;
int redRightSideButton = 0;
int blueLeftSideButton = 0;
int blueRightSideButton= 0;

//What am I doing with LVGl??
lv_obj_t * redLeftButton;
lv_obj_t * redLeftButtonLabel;
lv_obj_t * redRightButton;
lv_obj_t * redRightButtonLabel;
lv_obj_t * blueLeftButton;
lv_obj_t * blueLeftButtonLabel;
lv_obj_t * blueRightButton;
lv_obj_t * blueRightButtonLabel;
// lv_obj_t * myLabel;

lv_style_t redLeftButtonStyleREL; //relesed style
lv_style_t redLeftButtonStylePR; //pressed style
lv_style_t redRightButtonStyleREL; //relesed style
lv_style_t redRightButtonStylePR; //pressed style
lv_style_t blueLeftButtonStyleREL; //relesed style
lv_style_t blueLeftButtonStylePR; //pressed style
lv_style_t blueRightButtonStyleREL; //relesed style
lv_style_t blueRightButtonStylePR; //pressed style

static lv_res_t btn_click_action(lv_obj_t * btn) {
    uint8_t id = lv_obj_get_free_num(btn); //id usefull when there are multiple buttons

    if(id == 0)
    {
        char buffer[100];
		sprintf(buffer, "button was clicked %i milliseconds from start", pros::millis());
		lv_label_set_text(redLeftButtonLabel, buffer);
		redLeftSideButton = 1;
    }
	if(id == 1)
    {
        char buffer[100];
		sprintf(buffer, "button was clicked %i milliseconds from start", pros::millis());
		lv_label_set_text(redRightButtonLabel, buffer);
		redRightSideButton = 1;
    }
	if(id == 2)
    {
        char buffer[100];
		sprintf(buffer, "button was clicked %i milliseconds from start", pros::millis());
		lv_label_set_text(blueLeftButtonLabel, buffer);
		blueLeftSideButton = 1;
    }
	if(id == 3)
    {
        char buffer[100];
		sprintf(buffer, "button was clicked %i milliseconds from start", pros::millis());
		lv_label_set_text(blueRightButtonLabel, buffer);
		blueRightSideButton = 1;
    }

    return LV_RES_OK;
}

void lvglInit(){
        lv_style_copy(&redLeftButtonStyleREL, &lv_style_plain);
    redLeftButtonStyleREL.body.main_color = LV_COLOR_MAKE(150, 0, 0);
    redLeftButtonStyleREL.body.grad_color = LV_COLOR_MAKE(150, 0, 0);
    redLeftButtonStyleREL.body.radius = 0;
    redLeftButtonStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

    lv_style_copy(&redLeftButtonStylePR, &lv_style_plain);
    redLeftButtonStylePR.body.main_color = LV_COLOR_MAKE(255, 0, 0);
    redLeftButtonStylePR.body.grad_color = LV_COLOR_MAKE(255, 0, 0);
    redLeftButtonStylePR.body.radius = 0;
    redLeftButtonStylePR.text.color = LV_COLOR_MAKE(255, 255, 255);


        lv_style_copy(&redRightButtonStyleREL, &lv_style_plain);
    redRightButtonStyleREL.body.main_color = LV_COLOR_MAKE(150, 0, 0);
    redRightButtonStyleREL.body.grad_color = LV_COLOR_MAKE(150, 0, 0);
    redRightButtonStyleREL.body.radius = 0;
    redRightButtonStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

    lv_style_copy(&redRightButtonStylePR, &lv_style_plain);
    redRightButtonStylePR.body.main_color = LV_COLOR_MAKE(255, 0, 0);
    redRightButtonStylePR.body.grad_color = LV_COLOR_MAKE(255, 0, 0);
    redRightButtonStylePR.body.radius = 0;
    redRightButtonStylePR.text.color = LV_COLOR_MAKE(255, 255, 255);


        lv_style_copy(&blueLeftButtonStyleREL, &lv_style_plain);
    blueLeftButtonStyleREL.body.main_color = LV_COLOR_MAKE(0, 0, 150);
    blueLeftButtonStyleREL.body.grad_color = LV_COLOR_MAKE(0, 0, 150);
    blueLeftButtonStyleREL.body.radius = 0;
    blueLeftButtonStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

    lv_style_copy(&blueLeftButtonStylePR, &lv_style_plain);
    blueLeftButtonStylePR.body.main_color = LV_COLOR_MAKE(0, 0, 255);
    blueLeftButtonStylePR.body.grad_color = LV_COLOR_MAKE(0, 0, 255);
    blueLeftButtonStylePR.body.radius = 0;
    blueLeftButtonStylePR.text.color = LV_COLOR_MAKE(255, 255, 255);


        lv_style_copy(&blueRightButtonStyleREL, &lv_style_plain);
    blueRightButtonStyleREL.body.main_color = LV_COLOR_MAKE(0, 0, 150);
    blueRightButtonStyleREL.body.grad_color = LV_COLOR_MAKE(0, 0, 150);
    blueRightButtonStyleREL.body.radius = 0;
    blueRightButtonStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

    lv_style_copy(&blueRightButtonStylePR, &lv_style_plain);
    blueRightButtonStylePR.body.main_color = LV_COLOR_MAKE(0, 0, 255);
    blueRightButtonStylePR.body.grad_color = LV_COLOR_MAKE(0, 0, 255);
    blueRightButtonStylePR.body.radius = 0;
    blueRightButtonStylePR.text.color = LV_COLOR_MAKE(255, 255, 255);

    redLeftButton = lv_btn_create(lv_scr_act(), NULL); //create button, lv_scr_act() is deafult screen object
    lv_obj_set_free_num(redLeftButton, 0); //set button is to 0
    lv_btn_set_action(redLeftButton, LV_BTN_ACTION_CLICK, btn_click_action); //set function to be called on button click
    lv_btn_set_style(redLeftButton, LV_BTN_STYLE_REL, &redLeftButtonStyleREL); //set the relesed style
    lv_btn_set_style(redLeftButton, LV_BTN_STYLE_PR, &redLeftButtonStylePR); //set the pressed style
    lv_obj_set_size(redLeftButton, 200, 50); //set the button size
    lv_obj_align(redLeftButton, NULL, LV_ALIGN_IN_TOP_LEFT, 10, 10); //set the position to top mid

	redRightButton = lv_btn_create(lv_scr_act(), NULL); //create button, lv_scr_act() is deafult screen object
    lv_obj_set_free_num(redRightButton, 0); //set button is to 0
    lv_btn_set_action(redRightButton, LV_BTN_ACTION_CLICK, btn_click_action); //set function to be called on button click
    lv_btn_set_style(redRightButton, LV_BTN_STYLE_REL, &redRightButtonStyleREL); //set the relesed style
    lv_btn_set_style(redRightButton, LV_BTN_STYLE_PR, &redRightButtonStylePR); //set the pressed style
    lv_obj_set_size(redRightButton, 200, 50); //set the button size
    lv_obj_align(redRightButton, NULL, LV_ALIGN_IN_TOP_RIGHT, 10, 10); //set the position to top mid


	blueLeftButton = lv_btn_create(lv_scr_act(), NULL); //create button, lv_scr_act() is deafult screen object
    lv_obj_set_free_num(blueLeftButton, 0); //set button is to 0
    lv_btn_set_action(blueLeftButton, LV_BTN_ACTION_CLICK, btn_click_action); //set function to be called on button click
    lv_btn_set_style(blueLeftButton, LV_BTN_STYLE_REL, &blueLeftButtonStyleREL); //set the relesed style
    lv_btn_set_style(blueLeftButton, LV_BTN_STYLE_PR, &blueLeftButtonStylePR); //set the pressed style
    lv_obj_set_size(blueLeftButton, 200, 50); //set the button size
    lv_obj_align(blueLeftButton, NULL, LV_ALIGN_IN_BOTTOM_LEFT, 10, 10); //set the position to top mid

	blueRightButton = lv_btn_create(lv_scr_act(), NULL); //create button, lv_scr_act() is deafult screen object
    lv_obj_set_free_num(blueRightButton, 0); //set button is to 0
    lv_btn_set_action(blueRightButton, LV_BTN_ACTION_CLICK, btn_click_action); //set function to be called on button click
    lv_btn_set_style(blueRightButton, LV_BTN_STYLE_REL, &blueRightButtonStyleREL); //set the relesed style
    lv_btn_set_style(blueRightButton, LV_BTN_STYLE_PR, &blueRightButtonStylePR); //set the pressed style
    lv_obj_set_size(blueRightButton, 200, 50); //set the button size
    lv_obj_align(blueRightButton, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, 10, 10); //set the position to top mid


    redLeftButtonLabel = lv_label_create(redLeftButton, NULL); //create label and puts it inside of the button
    lv_label_set_text(redLeftButtonLabel, "Red Left"); //sets label text

	redRightButtonLabel = lv_label_create(redRightButton, NULL); //create label and puts it inside of the button
    lv_label_set_text(redRightButtonLabel, "Red Right"); //sets label text

	blueLeftButtonLabel = lv_label_create(blueLeftButton, NULL); //create label and puts it inside of the button
    lv_label_set_text(blueLeftButtonLabel, "Don't ask havn't learned this yet"); //sets label text

	blueRightButtonLabel = lv_label_create(blueRightButton, NULL); //create label and puts it inside of the button
    lv_label_set_text(blueRightButtonLabel, "Don't ask havn't learned this yet"); //sets label text

    // myLabel = lv_label_create(lv_scr_act(), NULL); //create label and puts it on the screen
    // lv_label_set_text(myLabel, "The button is broke"); //sets label text
    // lv_obj_align(myLabel, NULL, LV_ALIGN_CENTER, 10, 0); //set the position to center
}




void initialize() {
	void lvglInit();
	
	//Motor Brake Mode
	frontLeftDrive.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	middleLeftDrive.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	backLeftDrive.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	frontRightDrive.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	middleRightDrive.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	backRightDrive.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

	catapult.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

	//Sensor Calibration
	 pros::Imu potentiometer(9);
	 pros::delay(2000);
}



void disabled() {}



void competition_initialize() {}



void redRightSide() {
//translate(distance, voltage);
//intakeRotation(units, voltage)
	//setIntake(127);
//catapultRotation(units, voltage);
//rotate(degree, voltage)
// degree is + LEFT degree is - RIGHT
translate(50, 100);
intakeRotation(150, 127);
catapultRotation(50, 127);
rotate(90, 100);

}



void redLeftSide() {

}


void blueRightSide() {

}


void blueLeftSide() {

}



void autonomous() {
	//voltage range 127/-127 avoid <100
    if (redLeftSideButton == 1) {
        redLeftSide();
    } else if (redRightSideButton == 1) {
        redRightSide();
    } else if (blueLeftSideButton == 1) {
        blueLeftSide();
    } else if (blueRightSideButton == 1) {
        blueRightSide();
    }

	//redLeftSide();
	//blueRightSide();
	//blueLeftSide();

}



void opcontrol() {
	while(true) {
		setDriveMotors();
		setIntakeMotors();
		setCatapultMotors();

		pros::delay(10);
	}
}
