#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(2000);
	int i;
	for(i=0;i<4;i++)
	{
		Mtr_Run_lv(10500,-10000,0,0,0,0);
		Wait(2600);
		Mtr_Run_lv(10000,10000,0,0,0,0);
		Wait(800);
		Mtr_Run_lv(0,0,0,0,0,0);
	}


	return 0;
}

