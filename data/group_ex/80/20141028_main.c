

#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void motor(short right, short left) {
	Mtr_Run_lv(right,-left,0,0,0,0);
}

void stop(void) {
	motor(0,0);
	Wait(500);
}

void forward(void) {
	motor(10000,9500);
		Wait(1500);
		stop();
}

void turn(void) {
	motor(0,9500);
		Wait(850);
		stop();
}

void ex1(void) {                          /*5秒間で96.5cm進んだ→19.3cm/s*/
		Mtr_Run_lv(0,0,0,0,0,0);
		Wait(2000);
		Mtr_Run_lv(10000,-9500,0,0,0,0);  /*(right,left,0,0,0,0)*/
		Wait(5000);
}

void ex2(void) {
		Mtr_Run_lv(10000,-9500,0,0,0,0); /*1cm進む*/
			Wait(50);
		Mtr_Run_lv(0,0,0,0,0,0);
			Wait(2000);

		Mtr_Run_lv(10000,-9500,0,0,0,0); /*10cm進む*/
			Wait(500);
		Mtr_Run_lv(0,0,0,0,0,0);
			Wait(2000);

		Mtr_Run_lv(-10000,9500,0,0,0,0); /*5cm後退*/
			Wait(250);
		Mtr_Run_lv(0,0,0,0,0,0);
			Wait(2000);

		Mtr_Run_lv(10000,0,0,0,0,0); /*右に90°回転*/
			Wait(800);
		Mtr_Run_lv(0,0,0,0,0,0);
			Wait(2000);

		Mtr_Run_lv(10000,-9500,0,0,0,0);  /*左に360°回転*/
			Wait(3200);
		Mtr_Run_lv(0,0,0,0,0,0);
			Wait(2000);
}

void ex3(void) {

		Mtr_Run_lv(20000,-19000,0,0,0,0);  /*速度2倍10cm進む*/
			Wait(250);
		Mtr_Run_lv(0,0,0,0,0,0);
			Wait(2000);

		Mtr_Run_lv(5000,-4250,0,0,0,0);  /*速度1/2で10cm進む*/
			Wait(1000);
		Mtr_Run_lv(0,0,0,0,0,0);
			Wait(2000);
}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;

	for(i=0; i<4; i++) {

		forward();
		turn();
	}



	return 0;
}

