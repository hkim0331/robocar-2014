#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;

	for(i=0;i<100;i++){

	LED((i % 2)+1);
	Wait(100);
	if()
		{BuzzerSet(95,100);
		BuzzerStart();
		Wait(400);
		BuzzerStop();
		Wait(100);
		}
		else()
		{BuzzerSet(120,100);
		BuzzerStart();
		Wait(400);
		BuzzerStop();
		Wait(100);
		}
		}
	return 0;
}

