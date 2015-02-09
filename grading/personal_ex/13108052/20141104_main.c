#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void step(void)
{
	Mtr_Run_lv(10000,-10000,0,0,0,0);
	Wait(500);
	Mtr_Run_lv(0,0,0,0,0,0);
}

void ex1(void)
{
	int i;
	for(i=0; i<6; i++)
	{
		step();
		Wait(500);
	}
}


void ex2(void)
{
unsigned short left;

for(; ;)
   {
      step();
      Wait(500);
      left=ADRead(0);

    }
return 0;

}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	ex2();

	return 0;
}

