#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void step(void){

	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(60);
	Mtr_Run_lv(0,0,0,0,0,0);

}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i = 0;

	while(i<6){
		step();
	    Wait(500);
	    i++;
	}

	return 0;
}

