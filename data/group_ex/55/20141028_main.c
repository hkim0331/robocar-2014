#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	Wait(2000);

	int k;
	for(k=1;k<=4;k++){
		Mtr_Run_lv(9800, -10000, 0, 0, 0, 0);
		Wait(2750);
		Mtr_Run_lv(9800, 10000, 0, 0, 0, 0);
		Wait(700);
	}

	Mtr_Run_lv(0, 0, 0, 0, 0, 0);

	return 0;

}

