#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define Rb 700
#define Lb 700


void step(void){
	unsigned short right , left;
	for( ; ; ){
		right = ADRead(1);
		left = ADRead(0);

		if(right>Rb&&left>Lb){ //両見え
			break;
		}
		else if(right>Rb){ //右見え
			Mtr_Run_lv(0,-7000,0,0,0,0);
			LED(1);
		}
		else if(left>Lb){
			Mtr_Run_lv(7000,0,0,0,0,0);
			LED(2);
		}
		else{
			Mtr_Run_lv(7000,-7000,0,0,0,0);
			LED(0);
		}
	}
	Mtr_Run_lv(0,0,0,0,0,0);
	LED(3);

}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	step();

	return 0;
}

