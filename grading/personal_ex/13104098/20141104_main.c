#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void step()
{Mtr_Run_lv(10000,-10000,0,0,0,0);
Wait(100);
Mtr_Run_lv(0,0,0,0,0,0);
	}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


    step();
    Wait(500);
    step();
    Wait(500);
    step();
    Wait(500);
    step();
    Wait(500);
    step();
    Wait(500);
    step();
    Wait(500);

	return 0;
}

