#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define straight 20000, -20000, 0, 0, 0, 0
#define carb 20000, 20000, 0, 0, 0, 0
#define stop4 0,0,0,0,0,0
#define stop 2000
#define stop2 1500
#define stop3 250

void motor(void)
{
	int i;
	for (i=0;i<3;i++){
			 Mtr_Run_lv(straight);
			  Wait(stop2);
			  Mtr_Run_lv(carb);
			  Wait(stop3);
		}
	Mtr_Run_lv(straight);
		  Wait(stop2);
		  Mtr_Run_lv(stop4);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

 motor();

	return 0;
}

