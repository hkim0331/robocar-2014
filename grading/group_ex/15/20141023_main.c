#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


int play(m1,m2, Wait);

void forward(){
	Mtr_Run_lv(20000,-8000,0,0,0,0);
    Wait(1000);
}

void left(){
	Mtr_Run_lv(10000,0,0,0,0,0);
    Wait(1000);
    Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}




int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	forward();
	left();
	forward();
	left();
	forward();
    left();
    forward();
	left();

	Mtr_Run_lv(0, 0, 0, 0, 0, 0);

	  return 0;
}

