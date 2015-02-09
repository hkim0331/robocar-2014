#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

short l=10000, r=(-10000);

void run (short a, short b, unsigned int w)
{
	Mtr_Run_lv(a, b, 0, 0, 0, 0);
	Wait(w);
}
void turn_90 (short a, short b)
{
	Mtr_Run_lv(a, b, 0, 0, 0, 0);
	Wait(820);
}
void stop()
{
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i=0, j=0;

	for (j=0; j<4; j++)
	{
		for (i=0; i<30; i++)
		{
			run(l,r,75);
		}

		turn_90(l, 0);
		stop();
	}
	return 0;
}

