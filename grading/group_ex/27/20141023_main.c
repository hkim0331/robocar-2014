#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	int i;
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	for(i = 0;i < 4; i++){
	Wait(1000);
	Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
	Wait(1700);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	Mtr_Run_lv(10000, 10000, 0, 0, 0, 0);
	Wait(475);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
	}
	return 0;
}
