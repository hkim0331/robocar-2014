#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"



void go(void){
	Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
}

void stop(void){
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void tright(void){
	Mtr_Run_lv(-10000, -10000, 0, 0, 0, 0);
}

void tleft(void){
	Mtr_Run_lv(10000, 10000, 0, 0, 0, 0);
}

void start(void){
	unsigned short left;
	unsigned short right;

	left = ADRead(0);
	right = ADRead(1);

	Wait(1000);
	for (;;) {
		if(right > 500 && left >500){
			stop();
		}else if(right > 500){
			tright();
		}else if (left > 500){
			tleft();
		}else{
			go();
		}
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	start();

	return 0;
}

