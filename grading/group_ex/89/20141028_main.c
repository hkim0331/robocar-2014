#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"



void start(void)
{
	Wait(1000);
}

void str(int i, int t)
{
	Mtr_Run_lv(i, -i, 0, 0, 0, 0);
	Wait(t);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void turn(int i, int t)
{
	Mtr_Run_lv(i, 0, 0, 0, 0, 0);
	Wait(t);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void stop(int t)
{
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	Wait(t);
}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	start();
	str(10000, 2000);
	turn(10000, 750);
	str(10000, 2000);
	turn(10000, 750);
	str(10000, 2000);
	turn(10000, 750);
	str(10000, 2000);


	return 0;
}

