#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void run(int m1,int m2,int ms)
{
	Mtr_Run_lv(m1,m2,0,0,0,0);
	Wait(ms);
	Mtr_Run_lv(0,0,0,0,0,0);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	run(10000,10000,5000);
	return 0;
}

