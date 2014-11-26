#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
void step(void)
{
	Mtr_Run_lv(10000,-10000,0,0,0,0);
Wait(60);
Mtr_Run_lv(0,0,0,0,0,0);


	}

void step1(void)
{
Mtr_Run_lv(10000,10000,0,0,0,0);
Wait(60);
Mtr_Run_lv(0,0,0,0,0,0);
}

void step2(void)
{
Mtr_Run_lv(-10000,-10000,0,0,0,0);
Wait(60);
Mtr_Run_lv(0,0,0,0,0,0);
}

int i;
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short left,right;


	for(; ; ){
		step();
		Wait(60);
		left = ADRead(0);
		right = ADRead(1);

		if(left<550 && right<550)
		{
		step();
		}


		else if(left>600 && right<500)
		{
		step1();
		}
		else if(left<500 && right>600)
		{
		step2();
		}
		else if(left>650 && right>650)
		{
			break;
		}
	}
			return 0;

	}




