#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void play(int m1,int m2,int t){
	Mtr_Run_lv(m1,m2,0,0,0,0);
	Wait(t);
	Mtr_Run_lv(0,0,0,0,0,0);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	play(40000,-40000,5000);
	Wait(1000);


	return 0;
}

