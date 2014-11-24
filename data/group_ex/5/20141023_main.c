#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void Runf(void)
    {
	Mtr_Run_lv(12000, -11500, 0, 0, 0, 0);
	Wait(1875);
	}

void Stop(void)
    {
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	}

void turnR(void)
    {
	Mtr_Run_lv(0, -11500, 0, 0, 0, 0);
	}

void turnL(void)
    {
	Mtr_Run_lv(12000, 0, 0, 0, 0, 0);
	Wait(1000);
	}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Runf();

	turnL();

	Runf();

	turnL();

	Runf();

	turnL();

	Runf();

	Stop();

	return 0;
}

