#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
unsigned short left,right;

int black = 0;

void step1(void){
	Mtr_Run_lv(5000,-5000,0,0,0,0);
	Wait(1);
}

void step2(void){
	black += 1;
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(100);
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(500);
}

void step3(void){
	Mtr_Run_lv(9000,9000,0,0,0,0);
	Wait(30);
}

void step4(void){
	Mtr_Run_lv(-9000,-9000,0,0,0,0);
	Wait(30);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	for(;;){
		step1();
		left = ADRead(0);
		right = ADRead(1);
		if(left<500 && right<500){
			step1();
		}
		else if(left>500 && right>500){
			step2();
				if(black==25){
					Mtr_Run_lv(0,0,0,0,0,0);
					break;
				}
				else{
					BuzzerSet(160,100);
					BuzzerStart();
					Wait(250);
					BuzzerStop();
				}
			}
		else if(left>500){
			step3();
		}
		else if(right>500){
			step4();
		}
	}
Mtr_Run_lv(0,0,0,0,0,0);
Wait(10000);
	return 0;

}
