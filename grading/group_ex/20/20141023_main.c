#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	int i;

	for(i=0; i<4; i++){
	const unsigned short MainCycle = 60;
	Init(MainCycle);

    Wait(1000);
	Mtr_Run_lv(10500, -9950, 0, 0, 0, 0);
	Wait(3400);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	Wait(500);
	Mtr_Run_lv(10000, 10000, 0, 0, 0, 0);
	Wait(800);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	}

	return 0;
}
