#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void step(void)
{ Mtr_Run_lv(10000,-10000,0,0,0,0);//5ミリ前進、静止
Wait(80);
Mtr_Run_lv(0,0,0,0,0,0);}







int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;

	for(i=0;i<6;i++){
		step();

	}

	return 0;
}

