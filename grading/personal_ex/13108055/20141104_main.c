#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int step(int time){
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(time);
}

int stop(int time){
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(time);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	for(i=0;i<7;i++){
	step(100);
	stop(500);
	}
	return 0;
}

