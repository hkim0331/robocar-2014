#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void step(){
	Mtr_Run_lv(10030,-10000,0,0,0,0);
	Wait(200);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	for (;;) { 。
	    step();
	    Wait(500);
	}

	return 0;
}

