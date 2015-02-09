#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define SI
#define SO

void play(int pitch){
	BuzzerSet(pitch,100);
	BuzzerStart();
}

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	while(1){
		LED(1);
		play(SI)
		Wait(500);
		BuzzerStop();

		LED(2);
		play(SO);
		Wait(500);
		BuzzerStop();
	}

	return 0;
}

