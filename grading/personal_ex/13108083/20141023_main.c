#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void run (short a, short b)
{

	Mtr_Run_lv(a, b, 0, 0, 0, 0);

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(2000);

	Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
	Wait(70);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);

	Wait(1000);

	Mtr_Run_lv(10000, 0, 0, 0, 0, 0);

	Wait(1000);

	Mtr_Run_lv(0, -10000, 0, 0, 0, 0);



	return 0;
}

