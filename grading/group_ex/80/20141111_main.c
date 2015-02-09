#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int duration=5;


void motor(short right, short left) {
	Mtr_Run_lv(right,-left,0,0,0,0);
}


void stop(void) {
	motor(0,0);
	Wait(100);
}

void step(void) {
	motor(10000,9500);
	Wait(duration);
}

void Left(void) {
	motor(10000,0);
	Wait(duration);
}

void Right(void) {
	motor(0,9500);
	Wait(duration);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;


	unsigned short left;
	unsigned short right;


	    for( ; ; ) {


	        left = ADRead(0);
	        right = ADRead(1);

	        if (left<500 && right<500) {
	        	LED(3);
	        	step();
	        			}

	        	else if(left>=500 && right<500) {
	        		LED(1);
	        		Left();
	        	}

	        	else if(left<500 && right>=500) {
	        		LED(2);
	        		Right();
	        	}

	        	else {
	        		break;
	        	}
	    }

	    stop();
	    LED(0);



	return 0;
}

