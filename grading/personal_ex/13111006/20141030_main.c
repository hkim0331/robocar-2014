#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	Mtr_Run_lv(10000,10000,0,0,0,0);
	Wait(50);

    Mtr_Run_lv(0,0,0,0,0,0);
    Wait(50);

	return 0;
}

