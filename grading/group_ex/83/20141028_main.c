#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void ex1(void)
{
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(5000);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void ex2(void)
{
	Wait(2000);
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(5000);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void ex21(void)
{
	Wait(1000);
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(100);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void ex22(void)
{
	Wait(1000);
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(600);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void group(void)
{
	Wait(1500);
		Mtr_Run_lv(10000,-10000,0,0,0,0);
		Wait(1800);
		Mtr_Run_lv(15000,-5000,0,0,0,0);
		Wait(500);
		Mtr_Run_lv(10000,-10000,0,0,0,0);
		Wait(1800);
		Mtr_Run_lv(15000,-5000,0,0,0,0);
		Wait(500);
		Mtr_Run_lv(10000,-10000,0,0,0,0);
		Wait(1800);
		Mtr_Run_lv(15000,-5000,0,0,0,0);
		Wait(500);
		Mtr_Run_lv(10000,-10000,0,0,0,0);
		Wait(1800);
		Mtr_Run_lv(0,0,0,0,0,0);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	group();

	return 0;
}

