#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

unsigned short left;
unsigned short right;

void run()
{
	Mtr_Run_lv(10000,-10000,0,0,0,0);
}
void turnright()
{
	Mtr_Run_lv(0,-10000,0,0,0,0);
	Wait(30);
	Mtr_Run_lv(0,0,0,0,0,0);
}
void turnleft()
{
	Mtr_Run_lv(10000,0,0,0,0,0);
	Wait(30);
	Mtr_Run_lv(0,0,0,0,0,0);
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	for( ; ; )
	{
	run();
	left = ADRead(0);
	if(left>300)
	{
		turnleft();
	} else {

	}
	right = ADRead(1);
	if(right>300)
	{
		turnright();
	} else {

	}

	if((left>300)&&(right>300))
	{
		break;
	}
	}

	Mtr_Run_lv(0,0,0,0,0,0);

	return 0;
}

