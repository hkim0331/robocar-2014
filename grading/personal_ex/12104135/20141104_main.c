#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define fw 50 //1cm time


void run(int right, int left, int time)
{
	Mtr_Run_lv(right, -left, 0, 0, 0, 0);
	Wait(time);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void step(void)
{
	run(10500, 10000, fw/2);
}






int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;

	for (i=0; i<6; i++) {
	    step();
	    Wait(500);
	}



	return 0;
}

