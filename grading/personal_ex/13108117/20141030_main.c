#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void mtr(void)
{
	Wait(1000);
	Mtr_Run_lv(10000, 10000, 0, 0, 0, 0);
	Wait(25);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	Wait(1000);
}

void go(int n)
{int i;

	for(i=1; i<n; i++)
		{
		mtr();
		}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	go(10);

	return 0;
}
