#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
unsigned short lefti;
unsigned short righti;
unsigned int left;
unsigned int right;

void step(void)
{
	Mtr_Run_lv(right,left, 0, 0, 0, 0);
	Wait(100);
	Mtr_Run_lv(0,0,0,0,0,0);

}

void slalom(void)
{
	for ( ; ; )
	{
		step();
		Wait(100);
		lefti = ADRead(0);
		if(lefti > 700)
		{
			left=0;
		}else
		{
			left=-19000;
		}
		righti = ADRead(1);
		if(righti > 700){
			right=0;
		}else
		{
			right=18000;
		}
	}

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	slalom();
	return 0;
}

