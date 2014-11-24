#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void forword(void){
	Mtr_Run_lv(5000,-5000,0,0,0,0);
}
void stop(void){
	Mtr_Run_lv(0,0,0,0,0,0);
}
void turnr(void){
	Mtr_Run_lv(-5000,-5000,0,0,0,0);
}
void turnl(void){
	Mtr_Run_lv(5000,5000,0,0,0,0);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	unsigned short left,right;



	for(;;){

		left=ADRead(0);
		right=ADRead(1);

		if(left<400 && right<400){
			forword();
		}
		else if(left>700 && right<400){
			turnl();
		}
		else if(left<400 && right>700){
			turnr();
		}
		else if(left>700 && right>700){
			break;
		}
	}

	stop();

	return 0;
}
