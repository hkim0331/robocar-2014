#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"




int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

    unsigned short ADRead(unsigned char n);

    int i;

    for(i=0; i<100; i++){
	Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
	Wait(100);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	Wait(100);
    }
	return 0;
}

