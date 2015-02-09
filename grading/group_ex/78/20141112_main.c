#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void step(){

	Mtr_Run_lv(5000, -5000, 0, 0, 0, 0);

}
int i;
unsigned short left;
unsigned short right;

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	for(;;){

		step();
        Wait(50);

		left=ADRead(0);
		right=ADRead(1);
		if(800<left && right<500){

			Mtr_Run_lv(10000,0 , 0, 0, 0, 0);
			Wait(50);
			Mtr_Run_lv(0,0 , 0, 0, 0, 0);
		}
		else{;}
			if(800<right && left<500){

			Mtr_Run_lv(0,-10000 , 0, 0, 0, 0);
			Wait(50);
			Mtr_Run_lv(0,0, 0, 0, 0, 0);

			}
			else{;}
			if(right>800 && left>800){
				break;
			}
			else{;}


		}








	return 0;
}

