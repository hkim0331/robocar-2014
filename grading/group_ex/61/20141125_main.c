#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int i;
unsigned short left;
unsigned short right;
int blacks = 0;


void step(){
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(120);
	Mtr_Run_lv(0,0,0,0,0,0);
}
void gr1(){
	for( ; ; ){
		step();
		LED(0);
		Wait(1000);
		left = ADRead(0);
		right = ADRead(1);
		if(right<500 && left<500){
			blacks=0;
		}
		else if(right>500 && left>500){
			LED(3);
			blacks += 1;
			if(blacks == 4){
				break;	}
		}
		;
	}
}

void gr2(){
	for(;;){
		step();
		LED(0);
		Wait(1000);
		left = ADRead(0);
		right = ADRead(1);
		if(right<500 && left<500){
			break;
		}else if(right>500 && left>500){
			LED(3);
		}
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	gr1();
	gr2();
	gr1();
	gr2();


	return 0;
}

