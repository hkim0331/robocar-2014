#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

#define step();

	step();
	Wait(500);
	step();
	Wait(500);
	step();
	Wait(500);
	step();
	Wait(500);
	step();
	Wait(500);
	step();
	Wait(500);

	return 0;
}

