#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"



void step(void){
	int i;
	for(i=0; i<=3; i++){
	Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
	Wait(50);//5mm進む分
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	step();

	return 0;
}

