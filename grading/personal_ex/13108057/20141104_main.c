#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void step(void){
Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(500);
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(1000);
}

int main(void)
{

	int i;
	for (i=0; i<6; i++)
	{
	step();
	Wait(500);
	}


	const unsigned short MainCycle = 60;
	Init(MainCycle);



	return 0;
}

