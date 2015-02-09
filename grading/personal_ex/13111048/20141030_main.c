#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"



#define LEFT  9500
#define RIGHT 10000
#define FOWARD 830
#define N

void motor(short left, short right){
	Mtr_Run_lv(left, right, 0, 0, 0, 0);
}

void stop(void){
	motor(0,0);
}

void forward(){
	motor(LEFT,RIGHT);
	Wait(800);
	stop();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

/*	Mtr_Run_lv(10000, -9500, 0, 0, 0, 0);
	Wait(1000);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
*/


	for(;;){
		forward();
	}



	return 0;
}

