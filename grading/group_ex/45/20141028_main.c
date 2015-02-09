#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void wait(int sec)
{
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
		  Wait(1000*sec);
}

void go(int kyori)
{
	Mtr_Run_lv(10000, -10000, 0, 0, 0, 0);
	Wait(1000/17*kyori);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}

void turn()
{
	Mtr_Run_lv(-10000, -10000, 0, 0, 0, 0);
	Wait(450);
	Mtr_Run_lv(0, 0, 0, 0, 0, 0);
}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	  wait(2);
	  go(30);
	  turn();
	  go(30);
	  turn();
	  go(30);
	  turn();
	  go(30);


	return 0;
}

