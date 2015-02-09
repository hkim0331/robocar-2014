#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void ex1(void)
{
Wait(1000);
	Mtr_Run_lv(10000,-10000,0,0,0,0);

	Wait (1950);

	Mtr_Run_lv(10000,10000,0,0,0,0);
	Wait(590);
	Mtr_Run_lv(10000,-10000,0,0,0,0);

		Wait (1950);

		Mtr_Run_lv(10000,10000,0,0,0,0);
		Wait(590);
		Mtr_Run_lv(10000,-10000,0,0,0,0);

			Wait (1950);

			Mtr_Run_lv(10000,10000,0,0,0,0);
			Wait(590);
			Mtr_Run_lv(10000,-10000,0,0,0,0);

				Wait (1950);

				Mtr_Run_lv(10000,10000,0,0,0,0);
				Wait(590);

	Mtr_Run_lv(0,0,0,0,0,0);
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	ex1();







	return 0;
}

