#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void step1(void)
{
	Mtr_Run_lv(5000,-5000,0,0,0,0);
	Wait(50);

}
void step2(void)
{
	Mtr_Run_lv(-5000,-10000,0,0,0,0);
	Wait(80);

}
void step3(void)
{
	Mtr_Run_lv(10000,5000,0,0,0,0);
	Wait(80);

}
void step4(void)
{
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(120);

}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	unsigned short left;
	unsigned short right;
	for( ; ; ){
		left=ADRead(0);
		right=ADRead(1);

		if(left<500&&right<500){
			step1();
		}
		else if(left<500&&right>500){
			step2();
		}
		else if(left>500&&right<500){
			step3();
		}else{
			step4();
			break;
		}

	}

	return 0;
}

