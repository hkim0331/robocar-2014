#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void Go(void)
{
	Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
	Wait(100);
    Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void yomitori(void)
{
	if()
	{

	}
	else
	{

	}
}

int i;

void step(void)
{
	for (i=0; i<6; i++)
	{
	Go();
	Wait(500);
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	step();
	return 0;
}

