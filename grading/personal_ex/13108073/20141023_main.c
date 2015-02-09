#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(1000);
	Mtr_Run_lv(10000, 10000, 0, 0, 0, 0);
	Wait(750);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);    // エラー

	return 0;
}
