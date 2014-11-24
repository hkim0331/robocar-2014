#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void ex1(void)
{
	Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
	Wait(5000);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void Go(void)
{
	Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
	Wait(2200);
    Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void Turn(void)
{
	Mtr_Run_lv(10000, 0, 0, 0, 0, 0);
	Wait(800);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Go();
    Turn();
    Go();
    Turn();
    Go();
    Turn();
    Go();
    Turn();

	return 0;
}

