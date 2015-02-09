#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void run()
{

	Mtr_Run_lv(20000,-20000,0,0,0,0);
	Wait(5000);
	Mtr_Run_lv(0,0,0,0,0,0);

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(2000);

	run();
	return 0;

}
