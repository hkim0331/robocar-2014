#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
void step()
{
	Mtr_Run_lv(10500, -10600, 0, 0, 0, 0);
	Wait(33);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	Wait(500);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
    int i;
    for(i=0;i<6;i++)
    {
    	step();
    }
	return 0;
}

