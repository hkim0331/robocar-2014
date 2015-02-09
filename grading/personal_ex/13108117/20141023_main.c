#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void mtr(int mtr1, int mtr2)
{
	Wait(2000);
	Mtr_Run_lv(mtr1, mtr2, 0, 0, 0, 0);
	Wait(5000);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void run(void)
{
	mtr(10000, -10000);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	run();

	return 0;
}

