#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);


#define SO    120
#define SI    95

	Wait(1000);
	int i;
	for(i=0; i<100; i++)
	{

		LED((i%2)+1);
		if(i%2 == 0){
			play(SI);
		else
			play(SO);
		}
		Wait(100);
	}
LED(0);


	return 0;
}

