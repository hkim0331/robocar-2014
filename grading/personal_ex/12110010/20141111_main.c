#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
void play1(int pitch)
{
	BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(400);
	BuzzerStop();
	Wait(100);
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	LED(3);
	Wait(1000);
	int i;
	for(i=0;i<100;i++) {
		LED((i%2)+1);
		if((i%2)+1 == 1)
		{
			BuzzerSet(95,100);
		    BuzzerStart();
		}else
		{
			BuzzerSet(120,100);
			BuzzerStart();
		}
		Wait(100);
	}
	LED(0);
	return 0;
}

