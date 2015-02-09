#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void step(int time){

		  Mtr_Run_lv(11000, -10000, 0, 0, 0, 0);
		  Wait(time);
		  Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(1000);
	int i;
	for (i=0;i<6;i++){
	   step(27);
	   Wait(500);
    }

	return 0;
}

