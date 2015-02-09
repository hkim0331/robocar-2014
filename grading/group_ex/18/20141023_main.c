#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define DURATION 400
#define PAUSE 100
#define VOL 100

void front (void)
{
	Mtr_Run_lv(10500, -10000, 0, 0, 0, 0);
		     Wait(2500);
		     Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void right (void){
Mtr_Run_lv(10000, 0, 0, 0, 0, 0);
	     Wait(1000);
	     Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	 front();
	 right();
	 front();
	 right();
	 front();
	 right();
	 front();

	return 0;
}

