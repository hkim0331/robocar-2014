#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void mtr(int mtr1, int mtr2, int wait1)
{
	Wait(1000);
	Mtr_Run_lv(mtr1, mtr2, 0, 0, 0, 0);
	Wait(wait1);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	Wait(1000);
}

void go(int wait1)
{
	mtr(10000, -10000, wait1);
}

void back(int wait1)
{
	mtr(-10000, 10000, wait1);
}

void right(int wait1)
{
	mtr(0,-10000,wait1);
}

void left(int wait1)
{
	mtr(10000,0,wait1);
}

void sikaku(void)
{
	go(1000);
	right(650);
	go(1000);
	right(650);
	go(1000);
	right(650);
	go(1000);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	sikaku();

	return 0;
}

