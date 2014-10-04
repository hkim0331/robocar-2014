/* LEDs both on */
#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void run(void)
{
	LED(1); // green
	LED(2); // orange
	LED(0); // off
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	run();
	return 0;
}
