#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"



void step(void)
    {
		step();
	    Wait(500);
	}
    int i;

	for (i=0; i<6; i++)
	{
		step();
	    Wait(500);
	}
	int main(void)
	{
		const unsigned short MainCycle = 60;
		Init(MainCycle);
	return 0;
    }

