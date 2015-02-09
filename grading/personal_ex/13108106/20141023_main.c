#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define PAUSE 2000
#define PAUSE2 500

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	  Wait(PAUSE);
	Mtr_Run_lv(9500, -10000, 0, 0, 0, 0);
	  Wait(PAUSE2);
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);

	return 0;
}

