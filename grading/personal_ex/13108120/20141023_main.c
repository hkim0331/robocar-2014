#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#define DURATION 5000
#define Stop 0, 0, 0, 0, 0, 0

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(1000);
	Mtr_Run_lv(15000, -10000, 0, 0, 0, 0);
	Wait(DURATION);
	Mtr_Run_lv(Stop);

	return 0;
}
