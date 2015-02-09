#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void step(){
	Mtr_Run_lv(10050,-10000,0,0,0,0);
	Wait(60);
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(60);
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i=0;
	for(i=0; i<6; i++){
		step();
		Wait(500);

	}


	return 0;
}

