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
		LED((i%2)+1);
		BuzzerSet(95,100);
		BuzzerStart();
		Wait(1000);
		BuzzerStop();
		BuzzerSet(120,100);
		BuzzerStart();
		Wait(1000);
		BuzzerStop();
		Wait(100);
	}
	LED(0);
	return 0;
}

