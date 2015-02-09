#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define n 10
#define left 10000
#define right 10000

void run(void)
{

	Mtr_Run_lv(left,-right,0,0,0,0);
	Wait(25);
	Mtr_Run_lv(0,0,0,0,0,0);

}
int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);
	int i;
	for (i=0;i<n;i++)
	{
		run();
	}


	return 0;

}
