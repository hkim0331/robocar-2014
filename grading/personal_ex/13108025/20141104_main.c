#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void step(void){

	    Mtr_Run_lv(10000,-10000,0,0,0,0);
	    Wait(25);
	    Mtr_Run_lv(0,0,0,0,0,0);
}

void ex1(void){
step();
}

void ex2(void){
int i;
for(i=0; i<6; i++){
	step();
	Wait(500);	}
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	//ex1();
ex2();

	return 0;

}

