#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

void main(void)
{
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(200);

}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	return 0;
}

