#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int ex1(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(2000);
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(5000);
	Mtr_Run_lv(0,0,0,0,0,0);
	return 0;
}

int ex2(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(2000);
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(500);
	Mtr_Run_lv(0,0,0,0,0,0);
	return 0;
}

int ex3(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(2000);
	Mtr_Run_lv(-10000,10000,0,0,0,0);
	Wait(205);
	Mtr_Run_lv(0,0,0,0,0,0);
	return 0;
}

int ex4(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(2000);
	Mtr_Run_lv(-10000,-10000,0,0,0,0);
	Wait(600);
	Mtr_Run_lv(0,0,0,0,0,0);
	return 0;
}

int ex5(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(2000);
	Mtr_Run_lv(10000,10000,0,0,0,0);
	Wait(164);
	Mtr_Run_lv(0,0,0,0,0,0);
	return 0;
}

int ex(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(1000);
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(1500);
	Mtr_Run_lv(-10000,-10000,0,0,0,0);
	Wait(500);
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(1500);
	Mtr_Run_lv(-10000,-10000,0,0,0,0);
	Wait(500);
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(1500);
	Mtr_Run_lv(-10000,-10000,0,0,0,0);
	Wait(500);
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(1500);
	Mtr_Run_lv(0,0,0,0,0,0);
	return 0;
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	ex();

	return 0;
}
