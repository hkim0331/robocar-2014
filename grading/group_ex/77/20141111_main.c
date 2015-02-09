#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void step(void)
{
	Mtr_Run_lv(6000,-6000,0,0,0,0);

}

void migimawari(void)
{
	Mtr_Run_lv(-7500,-7500,0,0,0,0);
}

void hidarimawari(void)
{
	Mtr_Run_lv(7500,7500,0,0,0,0);
}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

		unsigned short left,right;
		for(;;){
			left=ADRead(0);
			right = ADRead(1);
			if(left<300 && right <300){
				step();
				Wait(10);
			}else if(left>800){
				hidarimawari();
			}else if(right>800){
				migimawari();
			}else if(left>700 && right>700){
				Mtr_Run_lv(0,0,0,0,0,0);
				Wait(100);
				break;
			}
		}

		Mtr_Run_lv(0,0,0,0,0,0);
		Wait(100);
	return 0;
}

