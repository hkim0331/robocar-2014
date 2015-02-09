#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void Straight(void){
	Mtr_Run_lv(6000,-6000,0,0,0,0);
}

void Right(void){
	Mtr_Run_lv(0,-8000,0,0,0,0);
}

void Left(void){
Mtr_Run_lv(8000,0,0,0,0,0);
}


void stop(void){
	Mtr_Run_lv(0,0,0,0,0,0);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short left,right;
			for( ; ; ){

			left=ADRead(0);
			right=ADRead(1);

		if(left>500 && right<500){
	Left();
	LED(2);
		}
		else if(right>500 &&left<500){
			Right();
			LED(1);
		}
		else if(left>500 && right>500){
			stop();
			LED(0);
		}
			else{
				Straight();
				LED(3);
			}
			}
	return 0;
}

