#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void ST(void){
	Mtr_Run_lv(20000, -20000, 0, 0, 0, 0);
		  Wait(700);
}

void TU(void){
	Mtr_Run_lv(0, -20000, 0, 0, 0, 0);
		  Wait(330);
}

void WA(void){
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
		  Wait(2000);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	  Init(MainCycle);

	  WA();
	  ST();
	  TU();
	  ST();
	  TU();
	  ST();
	  TU();
	  ST();
	  WA();



	return 0;
}

