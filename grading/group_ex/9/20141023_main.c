#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void Right(void){
	Mtr_Run_lv(10000,0,0,0,0,0);
}
void Straight(void){
	Mtr_Run_lv(10000,-7000,0,0,0,0);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	 Straight();
	  Wait(3000);
	 Right();
	  Wait(1000);
	 Straight();
	  Wait(3000);
	 Right();
	  Wait(1000);
	 Straight();
	  Wait(3000);
	 Right();
	  Wait(1000);
	 Straight();
	  Wait(3000);
	 Right();
	  Wait(1000);
	  Mtr_Run_lv(0, 0, 0, 0, 0, 0);


	return 0;
}

