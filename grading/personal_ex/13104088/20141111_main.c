#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	LED(3);
	Wait(1000);

	int i;
	for(i=0;i<10;i++)
	{
		LED(1+(i%2));
		Wait(100);

		BuzzerSet(142+37*(i%2),100);
		BuzzerStart();
		Wait(100);
		BuzzerStop();
	}
	LED(0);

	return 0;
}

