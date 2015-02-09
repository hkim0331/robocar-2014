#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define GO 10000, -10000, 0, 0, 0, 0
#define ST 0, 0, 0, 0, 0, 0
#define TR 10000, 10000, 0, 0, 0, 0
#define TL -10000, -10000, 0, 0, 0, 0




int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;

	for (i=0; i<=2; i++)

	{
	Mtr_Run_lv(GO);
	Wait(2000);
	Mtr_Run_lv(TR);
	Wait(500);

	}

	Mtr_Run_lv(GO);
	Wait(2000);
	Mtr_Run_lv(ST);

	return 0;
}

