#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void step(void){
	Mtr_Run_lv(10000,-8000,0,0,0,0);
	Wait(300);
	Mtr_Run_lv(0,0,0,0,0,0);
	Wait(300);
}
/*ex1*/
void ex1(void){

	int i;
	for (i=0; i<100; i++){
	step();
	Wait(500);
	}
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
ex1();

	return 0;
}

