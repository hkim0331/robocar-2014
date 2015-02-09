#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int step()
{
Mtr_Run_lv(6000,-6000,0,0,0,0);
Wait(10);

return 0;
	}

int motera()
{
Mtr_Run_lv(10000,5000,0,0,0,0);
Wait(10);

return 0;
	}

int moterb()
{
Mtr_Run_lv(-5000,-10000,0,0,0,0);
Wait(10);

return 0;
	}

int stop()
{
Mtr_Run_lv(0,0,0,0,0,0);

	}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	unsigned short left;
	unsigned short right;




	for(; ;)
	{
	left = ADRead (0);
    right = ADRead (1);
	if(right<300 && left<300)
	{
	step();
	}else{
	if(300<right && left<300)
	{
	moterb();
	}else{
	if(right<300 && 300<left)
	{
	motera();
	}else{
		stop();
	}
	}

	}



   }

	return 0;
}

