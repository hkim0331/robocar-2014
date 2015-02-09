#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int ex1(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
    Wait(1000);
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(70);
	Mtr_Run_lv(0,0,0,0,0,0);

	return 0;
}

int ex2(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	int i;
	for (i=0; i<6; i++) {
		Mtr_Run_lv(10000,-10000,0,0,0,0);
		Wait(50);
	}
	Mtr_Run_lv(0,0,0,0,0,0);
	return 0;
}

int ex3(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	int i;
	for (; ;) {
		Mtr_Run_lv(10000,-10000,0,0,0,0);
		Wait(50);

	}

	return 0;
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	ex1();

	return 0;
}
