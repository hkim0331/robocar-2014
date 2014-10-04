/* LED on and off */
#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void run(void)
{
	int i;
	int led;

	i=1;
	while (1==1) {
		led=i % 2; 	// i = 1 or 0.
		LED(led); 	// green or off.
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
