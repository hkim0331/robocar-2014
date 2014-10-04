/* LED on and off */
#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void run(void)
{
	int i;
	int led;

	for (i=0; i<10 ; i++) {
		LED(1);		// green.
		Wait(1000);
		LED(0);		// off.
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	run();
	return 0;
}
