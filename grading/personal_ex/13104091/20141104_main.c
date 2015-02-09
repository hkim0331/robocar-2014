#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"



void str (int dis){
	Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
	  Wait(1000/13*dis);
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}

void turL(){
	Mtr_Run_lv(10000, 10000, 0, 0, 0, 0);
		  Wait(500);
		  Mtr_Run_lv(0, 0, 0, 0, 0, 0);

}

void step(){
	str(0.5);
	Wait(5000);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	for(;;){
		step();
	}


	return 0;
}

