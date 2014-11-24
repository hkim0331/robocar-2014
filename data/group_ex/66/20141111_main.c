#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"





void forward(void)
{
	Mtr_Run_lv(15000,-15000,0,0,0,0);
	Wait(50);
	Mtr_Run_lv(0,0,0,0,0,0);
}
void turnL(void)
{
	Mtr_Run_lv(0,-15000,0,0,0,0);
	Wait(30);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void turnR(void)
{
	Mtr_Run_lv(15000,0,0,0,0,0);
	Wait(30);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void stop(void)
{
	Mtr_Run_lv(0,0,0,0,0,0);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short readL;
	unsigned short readR;


	for(;;){

		readL = ADRead(0);
		readR = ADRead(1);

		if(readR<=500&&readL<=500){
			forward();
		}
		else if(500<=readL&&500>readR){
			turnR();
		}
		else if(500<=readR&&500>readL){
			turnL();
		}
		else {
			break;
		}
	}

	stop();

	return 0;
}

