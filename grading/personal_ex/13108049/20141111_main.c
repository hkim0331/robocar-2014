#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define SO 120
#define SI 95

void play(int pitch)
{
	BuzzerSet(pitch,100);
	BuzzerStart();
	Wait(1000);
	BuzzerStop();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int i;

	for(i=0;i<10;i++){
		LED(( i % 2 ) + 1 );
		if(i%1+1==1)
			play(120);
		if(i%1+1==2)
			play(95);
		Wait(1000);
	}
	LED(0);

	return 0;
}

