#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	BuzzerSet(120, 100);
	BuzzerStart();
	Wait(3000);
	BuzzerStop();

	return 0;
}

