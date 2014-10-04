/* LEDs both on */
#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void run(void)
{
	LED(1); 	// green
	Wait(1000);
	LED(0); 	// off
	Wait(1000);
	LED(1); 	// green
	Wait(1000);
	LED(0); 	// off
	Wait(1000);
	LED(1); 	// green
	Wait(1000);
	LED(0); 	// off
	Wait(1000);
	LED(1); 	// green
	Wait(1000);
	LED(0); 	// off
	Wait(1000);
	LED(1); 	// green
	Wait(1000);
	LED(0); 	// off
	Wait(1000);
	LED(1); 	// green
	Wait(1000);
	LED(0); 	// off
	Wait(1000);
	LED(1); 	// green
	Wait(1000);
	LED(0); 	// off
	Wait(1000);
	LED(1); 	// green
	Wait(1000);
	LED(0); 	// off
	Wait(1000);
	LED(1); 	// green
	Wait(1000);
	LED(0); 	// off
	Wait(1000);
	LED(1); 	// green
	Wait(1000);
	LED(0); 	// off
	Wait(1000);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	run();
	return 0;
}
