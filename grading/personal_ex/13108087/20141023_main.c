#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int go(int right, int left){
	Mtr_Run_lv(right,-left,0,0,0,0);
}

int lefturn(void){
	Mtr_Run_lv(a,0,0,0,0,0);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(2000);
	go(10000,-11000);
	Wait();

	return 0;
}
