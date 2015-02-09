#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{   inti=0;
	while(i<10)
	{step();
	Wait(500);
	i++;}
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	return 0;
}

