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


void step(void) {
	motor(10000,9500);
	Wait(25);
}




int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;

	for(i=0; i<6; i++) {
		step();
		stop();
	}

	return 0;
}

