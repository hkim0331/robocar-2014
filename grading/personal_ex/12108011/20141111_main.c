#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	LED(3);
	Wait(1000);
	int i;
	for (i=0; i<10; i++) {
		LED(1);
		BuzzerSet(95, 100);
		BzzerStart();
		Wait(100);
		BuzzerStop();
		LED(2);
		BuzzerSet(120, 100);
		BzzerStart();
		Wait(100);
		BuzzerStop();

	}


	return 0;
}

