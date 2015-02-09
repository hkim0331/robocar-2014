#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void right(void){
	Mtr_Run_lv(-10000, -11100, 0, 0, 0, 0);
	Wait(490);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void mae(void){
	Mtr_Run_lv(10000, -11100, 0, 0, 0, 0);
	Wait(1600);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	Wait(2000);

	int i;
	for(i=0;i<4;i++){
		mae();
		Wait(200);
		right();
		Wait(200);

	}


	return 0;
}

