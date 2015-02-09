#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  12000
#define RIGHT_POWER 12000
#define LEFT    1
#define RIGHT   0

#define LED_LEFT 2
#define LED_RIGHT 1

#define MM 20
#define GRAY 600
#define BLACK 890


void Buzzer(void){
	BuzzerSet(100,50);
	BuzzerStart();
	Wait(100);
	BuzzerStop();
}


void motor(short left, short right) {
	Mtr_Run_lv(left, -right, 0, 0, 0, 0);
}

void stop(void) {
	motor(0,0);
}

void forward(void) {
	motor(LEFT_POWER, RIGHT_POWER);
}

void turn(uint8_t dir) {
	if (dir == LEFT) {
		LED(LED_LEFT);
		motor(LEFT_POWER/2,RIGHT_POWER);
	} else if (dir == RIGHT) {
		LED(LED_RIGHT);
		motor(LEFT_POWER,RIGHT_POWER/2);
	}
}

void slowturn(uint8_t dir) {
	if (dir == LEFT) {
		motor(LEFT_POWER/5,RIGHT_POWER/2);
	} else if (dir == RIGHT) {
		motor(LEFT_POWER/2,RIGHT_POWER/5);
	}
}

void crank(uint8_t dir) {
	if (dir == LEFT) {
		LED(LED_LEFT);
		motor(-LEFT_POWER,RIGHT_POWER);
	} else if (dir == RIGHT) {
		LED(LED_RIGHT);
		motor(LEFT_POWER,-RIGHT_POWER);
	}
}


int is_black(uint8_t n) {
	return ADRead(n) > BLACK;
}

int is_white(uint8_t n) {
	return  ADRead(n) < GRAY;
}

int is_gray(uint8_t n) {
	return  ((ADRead(n) < BLACK) &&  (ADRead(n)>GRAY));
}


void start(void){
	int i;
	Wait(1000);
	for (i=0; i<2000; i++) {
		if (is_white(LEFT) && is_white(RIGHT)) {
			forward();
		} else if (is_black(LEFT) && is_black(RIGHT)) {
			forward();
		} else if (is_black(LEFT)) {
			turn(LEFT);
		} else if (is_black(RIGHT)) {
			turn(RIGHT);
		} else if (is_gray(LEFT)){
			slowturn(LEFT);
		} else if (is_gray(RIGHT)){
			slowturn(RIGHT);
		} else {
			;
		}
	}
}


void start2(void){
	int i;
	for (i=0; i<2000; i++) {
		if (is_white(LEFT) && is_white(RIGHT)) {
			forward();
		} else if (is_black(LEFT) && is_black(RIGHT)) {
			crank(RIGHT);
		} else if (is_black(LEFT)) {
			turn(LEFT);
		} else if (is_black(RIGHT)) {
			turn(RIGHT);
		} else if (is_gray(LEFT)){
			slowturn(LEFT);
		} else if (is_gray(RIGHT)){
			slowturn(RIGHT);
		} else {
			;
		}
	}
}

void start3(void){
	int i;
	for (i=0; i<2000; i++) {
		if (is_white(LEFT) && is_white(RIGHT)) {
			forward();
		} else if (is_black(LEFT) && is_black(RIGHT)) {
			crank(LEFT);
		} else if (is_black(LEFT)) {
			turn(LEFT);
		} else if (is_black(RIGHT)) {
			turn(RIGHT);
		} else if (is_gray(LEFT)){
			slowturn(LEFT);
		} else if (is_gray(RIGHT)){
			slowturn(RIGHT);
		} else {
			;
		}
	}
}

void start4(void){
	for (i=0; i<15000; i++) {
		if (is_white(LEFT) && is_white(RIGHT)) {
			forward();
		} else if (is_black(LEFT) && is_black(RIGHT)) {
			crank(RIGHT);
		} else if (is_black(LEFT)) {
			turn(LEFT);
		} else if (is_black(RIGHT)) {
			turn(RIGHT);
		} else if (is_gray(LEFT)){
			slowturn(LEFT);
		} else if (is_gray(RIGHT)){
			slowturn(RIGHT);
		} else {
			;
		}
	}
}

void start5(void){
	for (;;) {
		if (is_white(LEFT) && is_white(RIGHT)) {
			forward();
		} else if (is_black(LEFT) && is_black(RIGHT)) {
			crank(LEFT);
		} else if (is_black(LEFT)) {
			turn(LEFT);
		} else if (is_black(RIGHT)) {
			turn(RIGHT);
		} else if (is_gray(LEFT)){
			slowturn(LEFT);
		} else if (is_gray(RIGHT)){
			slowturn(RIGHT);
		} else {
			;
		}
	}
}





int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
    start();
    start2();
    start3();
    start4();
    start5();

	return 0;
}
