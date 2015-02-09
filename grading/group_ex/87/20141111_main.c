#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void step(void)
{
	Mtr_Run_lv(6000,-6000,0,0,0,0);
	Wait(100);
	Mtr_Run_lv(0,0,0,0,0,0);
}
void step1(void)
{
	Mtr_Run_lv(6000,-1000,0,0,0,0);
	Wait(100);
	Mtr_Run_lv(0,0,0,0,0,0);
}
void step2(void)
{
	Mtr_Run_lv(1000,-6000,0,0,0,0);
	Wait(100);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void ex1(void)
{
	unsigned short left, right;

	for(; ;)
	{
		step();
		left=ADRead(0);
		right=ADRead(1);

		if(left>600 && right<600)
		{
			step1();
		}
		else if(right>600 && left<600)
		{
			step2();
		}
		else if(right>600 && left>600)
		{
			break;
		}
	}

	Mtr_Run_lv(0,0,0,0,0,0);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	ex1();

	return 0;
}

