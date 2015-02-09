#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define SO 120
#define SI 95

void play(int pitch,int time)
	{
	    BuzzerSet(pitch, 100);
	    BuzzerStart();
	    Wait(time);
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
	for(i=0; i<100; i++){
	LED((i % 2) + 1);
	Wait(100);
	}
	LED(0);
	return 0;
}

