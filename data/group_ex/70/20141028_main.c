#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int forword(int time){
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(time);
}
int stop(int time){
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(time);
}
int turn90r(int time){
	Mtr_Run_lv(-10000,-10000,0,0,0,0);
	Wait(time);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	stop(2000);

	forword(1500);
	stop(1000);
	turn90r(500);
	stop(1000);

	forword(1500);
	stop(1000);
	turn90r(500);
	stop(1000);

	forword(1500);
	stop(1000);
	turn90r(500);
	stop(1000);

	forword(1500);
	stop(1000);

	return 0;
}

