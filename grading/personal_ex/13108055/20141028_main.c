#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	void motor(void);
	Mtr_Run_Lv(a,b,c,d,e,f);

	Wait(2000);
	motor();
	Wait(50);
	motor();

	return 0;
}

