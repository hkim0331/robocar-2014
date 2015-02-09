#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int step(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	Wait(500);
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(70);
	Mtr_Run_lv(0,0,0,0,0,0);
	return 0;
}

int main(void)
{
	int i;
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	for(i=0; i<6; i++)
	{
		step();
	}

	return 0;
}

