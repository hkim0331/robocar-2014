#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void go(void){
	Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
}

void left(void){
	Mtr_Run_lv(10000, 0, 0, 0, 0, 0);
}

void stop(void){
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void back(void){
	Mtr_Run_lv(-10000, 10000, 0, 0, 0, 0);
}

void right(void){
	Mtr_Run_lv(0, 10000, 0, 0, 0, 0);
}

void start(void){
	go();
	Wait(2000);
	left();
	Wait(620);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Wait(1000);
	int i;
	for (i=0; i<4; i++){
		start();
	}
	stop();


	return 0;
}

