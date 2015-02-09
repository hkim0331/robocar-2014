#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
void step(void)
{
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(100);
	Mtr_Run_lv(0,0,0,0,0,0);

}



void step3(void)
{
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(60);
	Mtr_Run_lv(0,0,0,0,0,0);

	LED(1);
	Wait(100);
	int i;
	for(i=0; i<100; i+=1){
		LED((i%2)+1);
		Wait(0);
	}
		LED(0);
}


int i;
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short left,right;


	for(; ; ){
		step();
		Wait(500);
		left = ADRead(0);
		right = ADRead(1);

		if(left<550 && right<550)
		{
			step();
		}


		else if(left>650 && right>650)
		{
			step3();
		}
	}
	return 0;

}




