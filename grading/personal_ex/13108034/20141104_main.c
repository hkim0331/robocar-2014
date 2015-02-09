#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"



void step(void){

	Mtr_Run_lv(10000,-9500,0,0,0,0);
	Wait(25);


}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	for(i=0;i<6;i++)   {
		step();
		Wait(500);
	}



	return 0;
}

