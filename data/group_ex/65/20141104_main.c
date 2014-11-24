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

void ex3(void)
{
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(200);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void ex4(void)
{
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(800);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void ex5(void)
{
	Mtr_Run_lv(-10000,10000,0,0,0,0);
	Wait(300);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void ex6(void)
{
	Mtr_Run_lv(-10000,-10000,0,0,0,0);
	Wait(600);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void ex7(void)
{
	Mtr_Run_lv(10000,10000,0,0,0,0);
	Wait(2000);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void ex8(void)
{
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(2200);
	Mtr_Run_lv(0,0,0,0,0,0);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	ex8();
	ex6();
	ex8();
	ex6();
	ex8();
	ex6();
	ex8();
	return 0;
}
