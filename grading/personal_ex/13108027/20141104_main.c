#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


	void step (void)
	{


		Mtr_Run_lv(10000, -10000,0,0,0,0);
		Wait(33);
		Mtr_Run_lv(0,0,0,0,0,0);

	}

	int main()

	{
		int i;
		for(i=0; i<100; i++)
		{
			step();
			unsigned short left;
			left = ADRead(1000);
		}
	}
	return 0;
}

