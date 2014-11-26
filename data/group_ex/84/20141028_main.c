#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void ex21(void)
{
	Mtr_Run_lv(0,0,0,0,0,0);
		Wait(2000);

		Mtr_Run_lv(10000,-10000,0,0,0,0);
		Wait(70);

		Mtr_Run_lv(0,0,0,0,0,0);
}

void ex22(void)
{
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(2000);

	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(700);

	Mtr_Run_lv(0,0,0,0,0,0);
}

void ex23(void)
{

	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(2000);

	Mtr_Run_lv(-10000,10000,0,0,0,0);
	Wait(350);

	Mtr_Run_lv(0,0,0,0,0,0);
}

void ex24(void)
{

	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(2000);

	Mtr_Run_lv(-10000,-10000,0,0,0,0);
	Wait(500);

	Mtr_Run_lv(0,0,0,0,0,0);
}

void ex25(void)
{

	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(2000);

	Mtr_Run_lv(10000,10000,0,0,0,0);
	Wait(2000);

	Mtr_Run_lv(0,0,0,0,0,0);
}

void ex31(void)
{
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(2000);

	Mtr_Run_lv(20000,-20000,0,0,0,0);
	Wait(350);

	Mtr_Run_lv(0,0,0,0,0,0);
}

void ex32(void)
{
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(2000);

	Mtr_Run_lv(5000,-5000,0,0,0,0);
	Wait(1400);

	Mtr_Run_lv(0,0,0,0,0,0);
}

void susumu(void)
{
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(2100);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void magaru(void)
{
	Mtr_Run_lv(-10000,-10000,0,0,0,0);
	Wait(440);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void kadai(void)
{
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(2000);

	susumu();
	magaru();
	susumu();
	magaru();
	susumu();
	magaru();
	susumu();

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	//ex21();
	//ex22();
	//ex23();
	//ex24();
	//ex25();
	//ex31();
	//ex32();
	kadai();

	return 0;
}

