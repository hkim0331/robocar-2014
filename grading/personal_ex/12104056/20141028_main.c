#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	Mtr_Run_lv(5000,-5000,0,0,0,0);
	Wait(2000);
	Mtr_Run_lv(0,0,0,0,0,0);


	return 0;
}

