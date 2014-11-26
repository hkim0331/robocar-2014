#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void step(){
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(50);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void turnR (){
	Mtr_Run_lv(-10000,-10000,0,0,0,0);
	Wait(100);
}

void turnL (){
	Mtr_Run_lv(10000,10000,0,0,0,0);
	Wait(100);
}
void stop(){
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(100);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	unsigned short left;
	unsigned short right;

	for(;;){
			left = ADRead(0);
			right = ADRead(1);
		if(left>600	){
			turnL();
		}
		if(right>600){
			turnR();
		}
		if((right<600)&&(left<600)){
			step();
		}
		if((right>600)&&(left>600)){
					break;
				}
	}
	stop();
	return 0;
}


