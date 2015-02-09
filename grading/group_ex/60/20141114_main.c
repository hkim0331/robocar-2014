#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define LEFT_POWER  6500
#define RIGHT_POWER -6500

void step(void) {
	Mtr_Run_lv(LEFT_POWER, RIGHT_POWER, 0, 0, 0, 0);
    Wait(60);
    Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

int main(void){
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	for (;;) {
	        step();
	        unsigned short left;
	        unsigned short right;
	        left = ADRead(0);
	        right = ADRead(1);
	        if (left>500 && right<500) {
	        	Mtr_Run_lv(6000, -3000, 0, 0, 0, 0);
	        	    Wait(200);
	        } else {
	            ;
	        }
	        if (left<500 && right>500) {
	        	Mtr_Run_lv(3000, -6000, 0, 0, 0, 0);
	        	    Wait(200);
	       	} else {
	       	     ;
	       	}
	        if (left>500 && right>500) {
	        	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	       	     break;
	       	} else {
	             ;
	       	}
	 }

	return 0;
}

