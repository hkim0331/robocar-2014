#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	Mtr_Run_lv(10000,-10000,0,0,0,0);
    Wait(48.54);
    Mtr_Run_lv(0,0,0,0,0,0);

    Mtr_Run_lv(10000,-10000,0,0,0,0);
    Wait(485.4);
    Mtr_Run_lv(0,0,0,0,0,0);

    Mtr_Run_lv(-10000,10000,0,0,0,0);
    Wait(242.72);
    Mtr_Run_lv(0,0,0,0,0,0);

    Mtr_Run_lv(0,-10000,0,0,0,0);
    Wait(1000);
    Mtr_Run_lv(0,0,0,0,0,0);

    Mtr_Run_lv(10000,0,0,0,0,0);
    Wait(1000);
    Mtr_Run_lv(0,0,0,0,0,0);

    Mtr_Run_lv(0,-20000,0,0,0,0);
    Wait(1000);
    Mtr_Run_lv(0,0,0,0,0,0);

	return 0;
}

