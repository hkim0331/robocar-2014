#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void step(void)
{
	Mtr_Run_lv(10000,-10000,0,0,0,0);
}

void stop(void)
{
	Mtr_Run_lv(0,0,0,0,0,0);
}

void Rkaiten (void)
{
	Mtr_Run_lv(10000,10000,0,0,0,0);
}

void Lkaiten (void)
{
	Mtr_Run_lv(-10000,-10000,0,0,0,0);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short left;
	unsigned short right;

	for (;;)	{

		left  = ADRead(1);
		right = ADRead(0);

		if (left > 800 && right < 400)	{
			Lkaiten();

		}	else if (right > 800 && left < 400) {
			Rkaiten();

		}	else if (right < 400 && left < 400) {
			step();
		}	else if (right > 800 && left > 800) {
			break;
		}	else {
			;
		}
	}
	stop();


	return 0;
}

