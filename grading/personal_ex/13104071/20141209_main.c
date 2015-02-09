#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void step(){
	Mtr_Run_lv(10000,-10000,0,0,0,0);

}
void step2(){
	Mtr_Run_lv(5000,-5000,0,0,0,0);

}

void turnR (){
	Mtr_Run_lv(-10000,-10000,0,0,0,0);
}

void turnL (){
	Mtr_Run_lv(10000,10000,0,0,0,0);
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
	int blacks = 0;

	LED(3);
	for(;;){
		left = ADRead(0);
		right = ADRead(1);
		if(left>600	){
			turnL();
		}
		if(right>600){
			turnR();
		}

		if((right<400)&&(left<400)){
			step();
		}
		if((460<right<490)&&(460<left<490)){
			step2();
		}
		if((right>600)&&(left>600)){
			blacks += 1;
			step();
			if(blacks>50){
				stop();
				break;
			}
		}
		//stop();

	}
	LED(0);
	return 0;
}
