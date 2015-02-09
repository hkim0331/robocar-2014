#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"


void SI(void)
{
	play(95);
}

void SO(void)
{
	play(120);
}


int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;
	LED(3);
	Wait(1000);
	for(i=0; i<10; i++){
		LED( (i % 2) +1 );
		if(((i%2)+1) == 1){
			SI();
		}	else	{
			SO();
		}
		Wait(100);
	}
	LED(0);
	Wait(1000);

	return 0;
}

