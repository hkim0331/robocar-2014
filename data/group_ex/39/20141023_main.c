#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	Wait(1000);

	int i;

	for(i=0; i<3; i++){

		Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
		Wait(1450);
		Mtr_Run_lv(10000, 0, 0, 0, 0, 0);
		Wait(950);
	}

	Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
	Wait(1450);

	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	Wait(1000);

	return 0;
}
