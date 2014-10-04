/* LED on and off
#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void run(void)
{
	int i;

	for (i=1; 1==1; i++) {
		LED(i % 3); 	// green, orange or off.
		Wait(1000);
		i++;
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	run();
	return 0;
}
