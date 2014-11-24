#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void step (void)
{

	Mtr_Run_lv(7200, -9000, 0, 0, 0, 0);
	Wait(50);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);


}

void rightstep (void)
{

	Mtr_Run_lv(7200, 0, 0, 0, 0, 0);
	Wait(100);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	Mtr_Run_lv(7200, -9000, 0, 0, 0, 0);
		Wait(50);
		Mtr_Run_lv(0, 0, 0, 0, 0, 0);


}

void leftstep (void)
{

	Mtr_Run_lv(0, -9000, 0, 0, 0, 0);
	Wait(100);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	Mtr_Run_lv(7200, -9000, 0, 0, 0, 0);
		Wait(50);
		Mtr_Run_lv(0, 0, 0, 0, 0, 0);


}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	unsigned short left,right;

	for ( ; ; ) {
		step();
		left = ADRead(0);
		right = ADRead(1);
		if(left > 500 && right < 500){
			rightstep ();
		}
	else if (left < 500 && right > 500){
		leftstep();
		}
	else if (left > 500 && right > 500){
		break;
	}
	else {
		;
	}
	}





    return 0;
	}




