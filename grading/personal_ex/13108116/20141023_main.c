#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void Motor(int run){

Mtr_Run_lv(run,-run,0,0,0,0);

}



int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	Motor(10000);
	Wait(70);
	Motor(0);

	return 0;
}

