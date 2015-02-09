#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void GO (void)
{
Mtr_Run_lv(11800, -10000, 0, 0, 0, 0);
Wait(2650);
}
void TURN (void)
{
	Mtr_Run_lv(11800, 10000, 0, 0, 0, 0);
	Wait(525);
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	GO();
	TURN();
	GO();
	TURN();
	GO();
	TURN();
	GO();
	Mtr_Run_lv(0,0,0,0,0,0);

	return 0;
}

