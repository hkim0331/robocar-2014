#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
int i;
void step(){
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(120);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void ex1(void)
{

	for(i=0;i<6;i++){
		step();
		Wait(500);
	}
}
int main(void)
{
	/*unsigned short left;*/

	const unsigned short MainCycle = 60;
	Init(MainCycle);

	ex1();
	//gr1();

	/*	for( ; ; ){
		Mtr_Run_lv(10000,-10000,0,0,0,0);
		Wait(120);
		Mtr_Run_lv(0,0,0,0,0,0);
	}*/

	return 0;
}

