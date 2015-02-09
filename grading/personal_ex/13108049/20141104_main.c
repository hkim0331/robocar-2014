#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"



void step(void)  /*5mmGO*/
{
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(25);
	Mtr_Run_lv(0,0,0,0,0,0);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	unsigned short left;

	for(i=0;i<6;i++){
		step();
		Wait(500);
		left = ADRead(0);

		if(800<left&&left<1000){

		}
		else{
			;
		}
	}


	return 0;
}

