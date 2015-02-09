#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void CM(void)
{
    Mtr_Run_lv(10500,-10300,0,0,0,0);
	Wait(5000*3/5);

	Mtr_Run_lv(0, 0,0,0,0,0);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	CM();

	return 0;
}

