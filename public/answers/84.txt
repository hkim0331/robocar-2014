#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void step(void)
{
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(110);
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(50);
}

void migi(void)
{
	Mtr_Run_lv(-10000,-10000,0,0,0,0);
	Wait(100);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void hidari(void)
{
	Mtr_Run_lv(10000,10000,0,0,0,0);
	Wait(100);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void tomaru(void)
{
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(100000);
	Mtr_Run_lv(0,0,0,0,0,0);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(1000);

	unsigned short left;
	unsigned short right;

	for( ; ; )
	{
		step();

		left = ADRead(0);
		right = ADRead(1);

		if(left>700){
			hidari();
		}
		else{	;	}

		if(right>700){
			migi();
		}
		else{  ;   }

		if(right>700){if(left>700){
			tomaru();
		}}
		else{  ;   }
	}

	return 0;
}
