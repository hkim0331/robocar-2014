#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{

	int i;

	for (i=0; i<6; i++)
	{
	    step();
	    Wait(500);
	}


	const unsigned short MainCycle = 60;
	Init(MainCycle);

	return 0;
}


