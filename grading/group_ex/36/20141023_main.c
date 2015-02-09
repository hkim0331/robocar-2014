#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define PAUSE 1500
#define PAUSE2 405
#define PAUSE3 1000
#define STRAIGHT 10000, -9990, 0, 0, 0, 0
#define ROT -10000,-10000, 0, 0, 0, 0
#define STOP 0, 0, 0, 0, 0, 0

void motor(void)
{
	int i;
	for (i=0;i<4;i++) {
		Mtr_Run_lv(STRAIGHT);
	    Wait(PAUSE);
	    Mtr_Run_lv(STOP);
	    Wait(PAUSE3);
	    Mtr_Run_lv(ROT);
	    Wait(PAUSE2);
	}
	Mtr_Run_lv(STOP);
}




int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	motor();

	return 0;
}

