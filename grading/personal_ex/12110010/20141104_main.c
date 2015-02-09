#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void step(void)
{
	Mtr_Run_lv(17500,-20000, 0, 0, 0, 0);
	Wait(500);
	Mtr_Run_lv(0,0,0,0,0,0);

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;

	for (i=0; i< 6; i++)
	{
		step();
		Wait(500);

	}

	return 0;
}

